#include "../../include/minishell.h"

void	free_cmd_data(void)
{
	ft_lstclear(&g_ms.cmd_table, destroy_t_commands);
}

void	free_expander(t_commands *cmd)
{
	free(cmd->cmd_list);
	free(cmd->path);
	free(cmd->envp);
	free_ptrs(cmd->envp_path);
}

void	destroy_t_commands(void *cmds)
{
	t_commands	*cmd;

	cmd = (t_commands *)cmds;
	free_ptrs(cmd->cmd_list);
	free(cmd->path);
	free(cmd->envp);
	free_ptrs(cmd->envp_path);
	free(cmd);
}
