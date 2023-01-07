#include "../../include/minishell.h"

int	id_token_count(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			id_count;

	id_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	return (id_count);
}

void	get_cmd_list(t_utils *data)
{
	int			cmd_count;
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	cmd_count = id_token_count(COMMAND);
	data->argv = ft_calloc(cmd_count + 1, sizeof(char*));
	node = g_ms.tks;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (tklist->id_token == COMMAND)
		{
			data->argv[i] = tklist->token;
			i++;
		}
		node = node->next;
	}
	data->argv[i] = NULL;
}

void	get_envp(t_utils *data)
{
	t_list	*env_node;
	size_t	count;
	int		i;

	i = 0;
	env_node = g_ms.env;
	count = ft_lstcount_nodes(env_node);
	data->envp = ft_calloc(count + 1, sizeof(char *));
	while (env_node)
	{
		data->envp[i] = (char *)env_node->content;
		env_node = env_node->next;
		i++;
	}
	data->envp[i] = NULL;
}
