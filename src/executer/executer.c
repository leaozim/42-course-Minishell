#include "../../include/minishell.h"

void	child_dup_redirection(int i)
{
	(void)i;
	// if (i == 0)
	// {
	// 	// dup2(g_ms.infd, STDIN_FILENO);
	// 	dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	// }
	// else if (i != g_ms.num_pipes) //pode ser que seja num_pipes + 1
	// {
	// 	dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
	// 	dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	// }
	// else
	// {
	// 	dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
	// 	// dup2(g_ms.outfd, STDOUT_FILENO);
	// }
}

// void	child_process_check(t_commands *cmd)
// {
// 	// if (check_path() == FALSE)
// 	// {
// 	// 	ft_putstr_fd("Minishell: ", STDERR_FILENO);
// 	// 	perror(g_ms.cmd_data.argv[0]);
// 	// 	g_ms.exit_status = COMMAND_NOT_FOUND;
// 	// 	free_commands();
// 	// 	exit(g_ms.exit_status);
// 	// }
// 	// child_dup_redirection(i);
// 	// close_pipes();
// 	child_process_execution();
// }

void	child_process_execution(t_commands *cmd)
{
	if (execve(cmd->path, cmd->cmd_list, cmd->envp) == -1)
	{
		free_expander(cmd);
		exit(errno);
	}
}

void	check_fork(t_commands *cmd)
{
	if (cmd->pid_fd < 0)
		exit(EXIT_FAILURE);
	if (cmd->pid_fd == 0)
		child_process_execution(cmd);
}

void	create_child_process(t_commands *cmd)
{
	cmd->pid_fd = fork();
	check_fork(cmd);
}

void	executer(void)
{
	t_commands cmd;

	init_cmd_data(&cmd);
	if (check_path(&cmd) == FALSE)
		printf("command not found\n");
	create_child_process(&cmd);
	wait_status(&cmd);
	free_expander(&cmd);
	// forking();
	// close_pipes();
	// wait_status();

	// free_ptrs(g_ms.cmd_data.path_envp);
	// free(g_ms.cmd_data.envp);
	// ft_free_int_array(g_ms.array_fd, g_ms.num_pipes + 1);
	// free(g_ms.pid_fd);
	// free(g_ms.cmd_data.tks);
}

void	wait_status(t_commands *cmd)
{
	waitpid(cmd->pid_fd, &g_ms.exit_status, 0);
	if (WIFEXITED(g_ms.exit_status))
		g_ms.exit_status = WEXITSTATUS(g_ms.exit_status);
	if (g_ms.exit_status != 0)
		msg_error_cmd_not_found(g_ms.exit_status, cmd->cmd_list[0]);
}

//command and search execution

// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH

// echo -n > test2 > test3 oi ola | ls | grep obj > test1 | ls -l

//open close read
//access dup dup2
//execve fork pipe
//unlink wait waitpid
