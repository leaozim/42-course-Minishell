#include "../../include/minishell.h"

void	free_expander(t_commands *cmd)
{
	free(cmd->cmd_list);
}

void	free_commands(void)
{
	free(g_ms.cmd_data.argv);
	free(g_ms.cmd_data.executable_path);
}
