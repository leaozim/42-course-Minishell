#include "../../include/minishell.h"

int	get_cmd_count(void)
{
	t_tokens	*next;
	t_list		*node;
	int			cmd_count;

	cmd_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == COMMAND)
			cmd_count++;
		node = node->next;
	}
	return (cmd_count);
}

char	**create_cmd_list(void)
{
	int			cmd_count;
	char		**arguments;
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	cmd_count = get_cmd_count();
	arguments = ft_calloc(cmd_count + 1, sizeof(char*));
	node = g_ms.tks;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (tklist->id_token == COMMAND)
		{
			arguments[i] = tklist->token;
			i++;
		}
		node = node->next;
	}
	arguments[i] = NULL;
	return (arguments);
}

char	**get_envp(void)
{
	char	**envp;
	t_list	*env_node;
	size_t	count;
	int		i;

	i = 0;
	env_node = g_ms.env;
	count = ft_lstcount_nodes(env_node);
	envp = ft_calloc(count + 1, sizeof(char *));
	while (env_node)
	{
		envp[i] = (char *)env_node->content;
		env_node = env_node->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
