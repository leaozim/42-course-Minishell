/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:06 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_env(int outfd)
{
	t_list	*env_node;

	env_node = g_ms.env;
	while (env_node)
	{
		if (ft_strchr((char *)env_node->content, EQUAL) != NULL)
			ft_putendl_fd((char *)env_node->content, outfd);
		env_node = env_node->next;
	}
}

void	create_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
}
