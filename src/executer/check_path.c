/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:45 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_cmd_executable(t_commands *cmd)
{
	if (ft_strchr(cmd->cmd_list[0], SLASH))
	{
		cmd->path = ft_strdup(cmd->cmd_list[0]);
		if (access(cmd->path, F_OK | X_OK) == 0)
			return (TRUE);
	}
	free(cmd->path);
	return (FALSE);
}

t_bool	check_path(t_commands *cmd, t_list *node)
{
	if (is_builtins(node) == TRUE)
		return (TRUE);
	if (is_cmd_executable(cmd) == TRUE)
		return (TRUE);
	else if (get_path(cmd) == TRUE)
		return (TRUE);
	return (FALSE);
}
