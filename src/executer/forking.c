#include "../../include/minishell.h"

void	fork_check(int i)
{
	if (g_ms.pid_fd[i] < 0)
		exit(EXIT_FAILURE);
	if (g_ms.pid_fd[i] == 0)
	{
		if (g_ms.infd == -1 && i == 0)
		{
			// free_de_tudo
			exit(EXIT_FAILURE);
		}
		child_process_check(i);
	}
}

void	forking(void)
{
	int	i;

	i = 0;
	while (g_ms.cmd_data.node)
	{
		get_cmd_data();
		check_open_files(g_ms.tks, &g_ms.infd, &g_ms.outfd);
		g_ms.pid_fd[i] = fork();
		fork_check(i);
		free_commands();
		i++;
	}
}
