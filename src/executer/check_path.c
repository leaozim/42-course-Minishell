#include "../../include/minishell.h"

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
