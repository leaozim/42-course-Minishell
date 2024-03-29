/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:30 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_id_token_before_pipe(int id, t_list *node)
{
	t_tokens	*next;
	int			id_count;

	id_count = 0;
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

int	count_tokens_before_pipe(t_list *node)
{
	t_tokens	*next;
	int			count;

	count = 0;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		node = node->next;
		count++;
	}
	return (count);
}

int	count_id_token(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			count;

	count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == id)
			count++;
		node = node->next;
	}
	return (count);
}

t_list	*ft_lstnew_free_me(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(node));
	return (node);
}

void	add_free_me(char **content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		ft_lstadd_back(&g_ms.free_me, ft_lstnew(content[i]));
		i++;
	}
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(content));
}
