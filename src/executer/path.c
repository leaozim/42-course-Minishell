#include "../../include/minishell.h"

void	get_envp(void)
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

void	split_envp_path(void)
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

t_bool	get_executable_path(void)
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