#include "../../include/minishell.h"

void	wait_status(void)
{
	int		i;

	i = 0;
	while (i < g_ms.num_cmds)
	{
		waitpid(g_ms.pid_fd[i], (int *)&g_ms.exit_status, 0);
		if (WIFEXITED(g_ms.exit_status))
			g_ms.exit_status = WEXITSTATUS(g_ms.exit_status);
		i++;
	}
}
