#include "../../include/minishell.h"

void	wait_status(void)
{
	int		i;
	// char	*cmd;
	i = 0;
	// cmd = ((t_commands *)g_ms.cmd_table->content)->cmd_list[0];
	while (i < g_ms.num_cmds)
	{
		waitpid(g_ms.pid_fd[i], (int *)&g_ms.exit_status, 0);
		if (WIFEXITED(g_ms.exit_status))
			g_ms.exit_status = WEXITSTATUS(g_ms.exit_status);
		// if (g_ms.exit_status != 0)
		// 	msg_error_cmd_not_found(g_ms.exit_status, cmd);
		i++;
	}
}
