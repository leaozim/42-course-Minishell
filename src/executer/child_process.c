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
	if (check_path() == FALSE)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		perror(g_ms.cmd_data.argv[0]);
		g_ms.exit_status = COMMAND_NOT_FOUND;
		free_commands();
		exit(g_ms.exit_status);
	}
	child_dup_redirection(i);
	close_pipes();
	child_process_execution();
}

void	child_process_execution(void)
{
	printf(BLACK"\nPATH\n"RESET);
	printf(MAGENTA"%s\n"RESET, g_ms.cmd_data.executable_path);
	printf(BLACK"\nARGV\n"RESET);
	printf(MAGENTA"%s\n"RESET, g_ms.cmd_data.argv[0]);
	printf(BLACK"\nENVP\n"RESET);
	printf(MAGENTA"%s\n"RESET, g_ms.cmd_data.envp[0]);
	if (execve(g_ms.cmd_data.executable_path, g_ms.cmd_data.argv, g_ms.cmd_data.envp) == -1)
	{
		free_commands();
		exit(errno);
	}
}