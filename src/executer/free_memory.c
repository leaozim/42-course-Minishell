#include "../../include/minishell.h"

void	free_cmd_data(void)
{
	ft_lstclear(&g_ms.cmd_table, destroy_t_commands);
	ft_free_int_array(g_ms.array_fd, g_ms.num_pipes);
	free(g_ms.pid_fd);
}

void	destroy_t_commands(void *cmds)
{
	t_commands	*cmd;

	cmd = (t_commands *)cmds;
	free_ptrs(cmd->cmd_list);
	// free(cmd->cmd_list);
	free(cmd->path);
	free(cmd->envp);
	free(cmd->argv);
	free(cmd->id);
	free_ptrs(cmd->envp_path);
	ft_lstclear(&cmd->builtins_cmd_list, NULL);
	ft_lstclear(&cmd->argv_list, free);
	free(cmd);
}
