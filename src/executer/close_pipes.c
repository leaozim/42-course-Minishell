#include "../../include/minishell.h"

void	close_pipes(void)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)g_ms.cmd_table->content)->infd;
	outfd = ((t_commands *)g_ms.cmd_table->content)->outfd;
	if (infd > 0)
		close (infd);
	close(outfd);
}
