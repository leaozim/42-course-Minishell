#include "../../include/minishell.h"

int	count_id_token_before_pipe(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			id_count;

	id_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	return (id_count);
}

int	count_id_token(int id)
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

void	get_envp()
{
	t_list	*env_node;
	size_t	count;
	int		i;

	i = 0;
	env_node = g_ms.env;
	count = ft_lstcount_nodes(env_node);
	g_ms.cmd_data.envp = ft_calloc(count + 1, sizeof(char *));
	while (env_node)
	{
		g_ms.cmd_data.envp[i] = (char *)env_node->content;
		env_node = env_node->next;
		i++;
	}
	g_ms.cmd_data.envp[i] = NULL;
}

void	split_envp_path()
{
	t_list	*env_node;

	env_node = g_ms.env;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
			g_ms.cmd_data.path_envp = ft_split(env_node->content, ':');
		env_node = env_node->next;
	}
}

t_bool	get_executable_path()
{
	char	*path_slash;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", g_ms.cmd_data.argv[0]);
	while (g_ms.cmd_data.path_envp[i] != NULL)
	{
		g_ms.cmd_data.executable_path = ft_strjoin(g_ms.cmd_data.path_envp[i], path_slash);
		if (access(g_ms.cmd_data.executable_path, F_OK | X_OK) == 0)
		{
			free(path_slash);
			return (TRUE);
		}
		i++;
		free(g_ms.cmd_data.executable_path);
	}
	g_ms.cmd_data.executable_path = ft_strdup(g_ms.cmd_data.argv[0]);
	free(path_slash);
	return (FALSE);
}

t_bool	is_cmd_with_slash_executable()
{
	if (ft_strchr(g_ms.cmd_data.argv[0], SLASH))
	{
		g_ms.cmd_data.executable_path = ft_strdup(g_ms.cmd_data.argv[0]);
		if (access(g_ms.cmd_data.executable_path, F_OK | X_OK) == 0)
			return (TRUE);
		else
			free(g_ms.cmd_data.executable_path);
	}
	return (FALSE);
}

t_bool	is_cmd_executable(void)
{
	if (is_cmd_with_slash_executable() == TRUE)
		return (TRUE);
	else if (get_executable_path() == TRUE)
		return (TRUE);
	return (FALSE);
}

int	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf(RED"%s "RESET, array[i]);
		i++;
	}
	printf("\n");
	return (i);
}