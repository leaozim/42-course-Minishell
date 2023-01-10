#include "../../include/minishell.h"

// echo oi > temp1 > temp2 > temp3 ola

void	init_cmd_data(t_commands *cmd)
{
	cmd->node = g_ms.tks;
	cmd->envp_path = NULL;
	cmd->cmd_list = NULL;
	cmd->envp = NULL;
	cmd->path = NULL;
	cmd->num_pipes = count_id_token(PIPE);
	get_cmds(cmd);
	get_envp(cmd);
	get_envp_path(cmd);
}

// void	init_dynamic_cmd_data(void)
// {
// 	g_ms.array_fd = ft_calloc(g_ms.num_pipes, sizeof(int *)); // + 1
// 	g_ms.pid_fd = ft_calloc(g_ms.num_pipes, sizeof(int));     // + 1
// 	get_envp();
// 	split_envp_path();
// }