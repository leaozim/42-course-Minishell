#include "../../include/minishell.h"

void	get_linked_list_builtins(t_commands *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmd_list[++i])
		ft_lstadd_back(&cmd->builtins_cmd_list,
			ft_lstnew(cmd->cmd_list[i]));
}

t_arguments	*create_argv_content(char *argv, int index)
{
	t_arguments	*content;

	content = ft_calloc(1, sizeof(t_arguments));
	content->argv = argv;
	content->id_argv = index;
	return (content);
}

void	get_linked_list_argv(t_commands *cmd)
{
	int	i;

	i = -1;
	while (cmd->argv[++i])
		ft_lstadd_back(&cmd->argv_list,
			ft_lstnew(create_argv_content(cmd->argv[i], cmd->id[i])));
}
