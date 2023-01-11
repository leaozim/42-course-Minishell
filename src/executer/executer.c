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

// if (check_path(&cmd) == FALSE)
// 	printf("command not found\n");
// create_child_process(&cmd);
// wait_status(&cmd);

// void	create_cmd_table(void)
// {
// 	t_list		*node;
// 	// t_commands	*next;

// 	node = g_ms.tks;
// 	g_ms.cmd_table = ft_lstnew(NULL);
// 	while (node)
// 	{
// 		// next = ((t_commands *)node->content);
// 		ft_lstadd_back(&g_ms.cmd_table, ft_lstnew(create_cmd_node(&node)));
// 		node = node->next;
// 	}
// }

void	print_cmds(void)
{
	t_list		*node;
	t_commands	*cmd;
	int			i;
	t_commands	*cmd2;
	
	i = 0;
	int count = ft_lstcount_nodes(g_ms.cmd_table);
	printf("en = %d\n", count);
	node = g_ms.cmd_table;
	while (i < count)
	{
		cmd = ((t_commands *)node->content);
		printf(YELLOW"cmd = %s\n"RESET, cmd->cmd_list[0]);
		printf(MAGENTA"path = %s\n"RESET, cmd->path);
		node = node->next;
		i++;
	}
}

void	executer(void)
{
	t_list		*node;
	t_commands	*cmd;

	node = g_ms.tks;
	while (node)
	{
		cmd = ft_calloc(1, sizeof(t_commands)); //
		get_cmds(cmd, node);
		get_envp(cmd);
		get_envp_path(cmd);
		get_path(cmd);
		ft_lstadd_back(&g_ms.cmd_table, ft_lstnew(cmd));
		while (node && ((t_tokens *)node->content)->id_token != PIPE)
			node = node->next;
		if (node && ((t_tokens *)node->content)->id_token == PIPE)
			node = node->next;

	}
	print_cmds();
	ft_lstclear(&g_ms.cmd_table, destroy_t_commands);

	// ls echo | oi ola | uname yes

	// t_commands	*next;
	// next = ((t_commands *)g_ms.cmd_table->content);
	// g_ms.cmd_table = g_ms.cmd_table->next;
	// printf("%s\n", *next->cmd_list);
	// create_cmd_table();


	// free_expander(&cmd);
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




// while (node)
// {
// 	while (token != PIPE)
// 	{
// 		open_files(); // t_list = int, setar os fds(int) e os redirecionadores (t_bool - in_fd, out_fd, append_fd, heredoc_fd)
// 		char **cmds = get_comands(); // pegar cada comandos ok;
// 		char **argv = get_argv();

// 	}
// 	cmd_list->next;
// }