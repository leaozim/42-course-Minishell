#include "../../include/minishell.h"

// void	child_dup_redirection(int i)
// {
// 	if (i == 0)
// 	{
// 		// dup2(g_ms.infd, STDIN_FILENO);
// 		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
// 	}
// 	else if (i != g_ms.num_pipes) //pode ser que seja num_pipes + 1
// 	{
// 		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
// 		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
// 	}
// 	else
// 	{
// 		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
// 		// dup2(g_ms.outfd, STDOUT_FILENO);
// 	}
// }

void	child_process_check(t_list *node)
{
	// if (check_path() == FALSE)
	// {
	// 	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	// 	perror(g_ms.cmd_data.argv[0]);
	// 	g_ms.exit_status = COMMAND_NOT_FOUND;
	// 	free_commands();
	// 	exit(g_ms.exit_status);
	// }
	// child_dup_redirection(i);
	// close_pipes();
	child_process_execution(node);
}

void	child_process_execution(t_list *node)
{
	char	*path;
	char	**cmds;
	char	**envp;

	path = ((t_commands*)node->content)->path;
	cmds = ((t_commands*)node->content)->cmd_list;
	envp = ((t_commands*)node->content)->envp;
	if (execve(path, cmds, envp) == -1)
	{
		// free_commands();
		// exit(errno);
	}
}