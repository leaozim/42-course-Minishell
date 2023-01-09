#include "../../include/minishell.h"

void	free_expander(t_commands *cmd)
{
	free(cmd->path);
	free_ptrs(cmd->envp);
	// free_ptrs(cmd->cmd_list);
	// free_ptrs(cmd->envp);
}

void	free_commands(void)
{
	// free(g_ms.cmd_data.argv);
	// free(g_ms.cmd_data.executable_path);
}
