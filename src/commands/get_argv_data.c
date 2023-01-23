/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:32 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void	get_linked_list_builtins(t_commands *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmd_list[++i])
		ft_lstadd_back(&cmd->builtins_cmd_list,
			ft_lstnew(cmd->cmd_list[i]));
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->builtins_cmd_list));
}

t_arguments	*create_argv_content(char *argv, int index)
{
	t_arguments	*content;

	content = ft_calloc(1, sizeof(t_arguments));
	content->argv = argv;
	content->id_argv = index;
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(content));
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
