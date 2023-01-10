#include "../../include/minishell.h"

void	child_dup_redirection(int i)
{
	if (i == 0)
	{
		// dup2(g_ms.infd, STDIN_FILENO);
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	}
	else if (i != g_ms.num_pipes) //pode ser que seja num_pipes + 1
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	}
	else
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
		// dup2(g_ms.outfd, STDOUT_FILENO);
	}
}

void	child_process_check(int i)
{
	(void)i;
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
	// child_process_execution();
}

void	child_process_execution(void)
{
	// dprintf(2, BLACK"\nPATH\n"RESET);
	// dprintf(2, MAGENTA"%s\n"RESET, g_ms.cmd_data.executable_path);
	// dprintf(2, BLACK"\nARGV\n"RESET);
	// dprintf(2, MAGENTA"%s\n"RESET, g_ms.cmd_data.argv[0]);
	// dprintf(2, BLACK"\nENVP\n"RESET);
	// dprintf(2, MAGENTA"%s\n"RESET, g_ms.cmd_data.envp[0]);
	// dprintf(2, "%d\n", g_ms.outfd);
	// dup2(g_ms.array_fd[i], STDOUT_FILENO);
	if (execve(g_ms.cmd_data.executable_path, g_ms.cmd_data.argv, g_ms.cmd_data.envp) == -1)
	{
		free_commands();
		exit(errno);
	}
}