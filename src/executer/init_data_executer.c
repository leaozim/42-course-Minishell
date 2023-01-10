#include "../../include/minishell.h"

void	init_cmd_data(t_commands **cmd, t_list **node)
{
	if (node)
		printf("\n");
	(*cmd)->node = g_ms.tks;
	(*cmd)->envp_path = NULL;
	(*cmd)->cmd_list = NULL;
	(*cmd)->envp = NULL;
	(*cmd)->path = NULL;
	(*cmd)->num_pipes = count_id_token(PIPE);
	get_cmds((*cmd), *node);
	get_envp((*cmd));
	get_envp_path((*cmd));
}
