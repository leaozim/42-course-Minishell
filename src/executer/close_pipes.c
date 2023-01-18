#include "../../include/minishell.h"

void	close_pipes(void)
{
	int	i;
	int	infd;
	int	outfd;

	i = 0;
	if (g_ms.num_pipes > 0)
	{
		infd = ((t_commands *)g_ms.cmd_table->content)->infd;
		outfd = ((t_commands *)g_ms.cmd_table->content)->outfd;
		while (i < g_ms.num_pipes)
		{
			close(g_ms.array_fd[i][0]);
			close(g_ms.array_fd[i][1]);
			i++;
		}
		if (infd > 0)
			close(infd);
		close(outfd);
	}
}
