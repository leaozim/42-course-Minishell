#include "../../include/minishell.h"

void	free_expander(t_commands *cmd)
{
	free(cmd->cmd_list);
	free(cmd->path);
	free(cmd->envp);
	free_ptrs(cmd->envp_path);
}

void	free_commands(void)
{
	// free(g_ms.cmd_data.argv);
	// free(g_ms.cmd_data.executable_path);
}
