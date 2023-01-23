/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:26 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:20:27 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	delete_node(t_list **tlist, int key)
{
	t_list		*node;
	t_list		*prev;
	t_tokens	*token;

	node = *tlist;
	token = (t_tokens *)node->content;
	while (node)
	{
		token = (t_tokens *)node->content;
		if (token->index == key)
			break ;
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return ;
	prev->next = node->next;
	destroy_t_tokens(node->content);
	free(node);
}

void	join_tokens(t_list **tks)
{
	t_list		*node;
	t_tokens	*marker_position;
	t_tokens	*after_marker;
	char		*temp;

	node = *tks;
	if (!node->next)
		return ;
	while (node && \
	!ft_strchr(((t_tokens *)node->next->content)->token, MARKER))
	{
		node = node->next;
		if (node->next == NULL)
			return ;
	}
	marker_position = (t_tokens *)node->next->content;
	after_marker = (t_tokens *)node->next->next->content;
	temp = ft_strjoin(((t_tokens *)node->content)->token, after_marker->token);
	free(((t_tokens *)node->content)->token);
	((t_tokens *)node->content)->token = ft_strdup(temp);
	((t_tokens *)node->content)->id_token = COMMAND;
	free(temp);
	delete_node(&node, marker_position->index);
	delete_node(&node, after_marker->index);
	join_tokens(&g_ms.tks);
}
