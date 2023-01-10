#include "../../include/minishell.h"

void	close_pipes(void)
{
	int	i;
	
	i = 0;
	while (i < g_ms.num_pipes)
	{
		close(g_ms.array_fd[i][0]);
		close(g_ms.array_fd[i][1]);
		i++;
	}
	// if (g_ms.infd != -1)
	// 	close(g_ms.infd);
	// close(g_ms.outfd);
}