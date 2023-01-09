#include "../../include/minishell.h"

void	get_envp_path(t_commands *cmd)
{
	t_list	*env_node;

	env_node = g_ms.env;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
			cmd->envp_path = ft_split(env_node->content, ':');
		env_node = env_node->next;
	}
}

t_bool	get_path(t_commands *cmd)
{
	char	*path_slash;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", cmd->cmd_list[0]);
	while (cmd->envp_path[i] != NULL)
	{
		cmd->path = ft_strjoin(cmd->envp_path[i], path_slash);
		if (access(cmd->path, F_OK | X_OK) == 0)
		{
			return (free(path_slash), TRUE);
		}
		free(cmd->path);
		i++;
	}
	cmd->path = ft_strdup(cmd->cmd_list[0]);
	return (free(path_slash), FALSE);
}

t_bool	is_cmd_executable(t_commands *cmd)
{
	if (ft_strchr(cmd->cmd_list[0], SLASH))
	{
		cmd->path = ft_strdup(cmd->cmd_list[0]);
		if (access(cmd->path, F_OK | X_OK) == 0)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	check_path(t_commands *cmd)
{
	if (is_cmd_executable(cmd) == TRUE)
		return (TRUE);
	else if (get_path(cmd) == TRUE)
		return (TRUE);
	return (FALSE);
}