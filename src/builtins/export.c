/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msg_print_export(t_list **env_node, int outfd)
{
	char	*aux;
	char	*str;

	ft_putstr_fd("declare -x ", outfd);
	str = (char *)(*env_node)->content;
	if (ft_strchr(str, EQUAL) != NULL)
	{
		aux = ft_stop_chr(str, EQUAL);
		ft_putstr_fd(aux, outfd);
		ft_putchar_fd(DQUOTES, outfd);
		ft_putstr_fd(ft_strchr(str, EQUAL) + 1, outfd);
		ft_putchar_fd(DQUOTES, outfd);
		ft_putchar_fd('\n', outfd);
		free(aux);
	}
	else
		ft_putendl_fd((char *)(*env_node)->content, outfd);
}

int	print_export(t_list **env, int outfd)
{
	t_list	*env_node;

	env_node = *env;
	if (g_ms.size_node_builtin == 1)
	{
		while (env_node)
		{
			msg_print_export(&env_node, outfd);
			env_node = env_node->next;
		}
		return (1);
	}
	return (0);
}

t_bool	check_export_update_value(char *token)
{
	t_list	*env_node;
	char	*name;
	char	*content;

	env_node = g_ms.env;
	name = ft_findsubchr(token, EQUAL);
	while (env_node)
	{
		content = ft_findsubchr((char *)env_node->content, EQUAL);
		if (!ft_strcmp(name, content))
		{
			if (ft_strchr(token, EQUAL) != NULL)
				ft_strupdate((char **)&env_node->content, ft_strdup(token));
			return (free(content), free(name), TRUE);
		}
		free(content);
		env_node = env_node->next;
	}
	return (free(name), FALSE);
}

t_bool	export_update_value(char **next, t_list **node)
{
	if (check_export_update_value(*next) == TRUE)
	{
		g_ms.exit_status = 0;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}

int	builtin_export(t_list *node, int outfd)
{
	char	*next_cmd;

	if (print_export(&g_ms.env, outfd) == 1)
		return (g_ms.exit_status = 0, 0);
	while (node->next)
	{
		next_cmd = (char *)node->next->content;
		if (error_invalid_identifier(&next_cmd, &node, "export") == TRUE)
			continue ;
		if (export_update_value(&next_cmd, &node) == TRUE)
			continue ;
		ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(next_cmd)));
		node = node->next;
	}
	return (0);
}
