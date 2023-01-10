#include "../../include/minishell.h"

t_commands	*create_cmd_node(t_list **node)
{
	t_commands	*cmd;

	cmd = ft_calloc(1, sizeof(t_commands));
	// cmd->num_pipes = count_id_token(PIPE);
	get_cmds(cmd, *node);
	get_envp(cmd);
	get_envp_path(cmd);
	return (cmd);
}
