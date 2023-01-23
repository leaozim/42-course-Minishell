/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:41 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reidentify_some_tokens(t_list *tks)
{
	t_list		*node;
	t_tokens	*tokens;
	t_tokens	*next_tokens;

	node = tks;
	while (node)
	{
		tokens = (t_tokens *)node->content;
		if (is_metachars(tokens->id_token) && tokens->id_token != PIPE && \
			node->next)
		{
			next_tokens = (t_tokens *)node->next->content;
			if (tokens->id_token == HEREDOC)
				next_tokens->id_token = DELIMITER;
			else if (tokens->id_token == APPEND)
				next_tokens->id_token = FILE_APPEND;
			else if (tokens->id_token == RDRCT_IN)
				next_tokens->id_token = FILE_IN;
			else if (tokens->id_token == RDRCT_OU)
				next_tokens->id_token = FILE_OUT;
			else
				next_tokens->id_token = COMMAND;
		}
		node = node->next;
	}
}

int	error_syntaxy_metachars(t_list *tks, int len_tokens)
{
	t_list		*node;
	t_tokens	*tkl;
	t_tokens	*next;
	int			i;

	node = tks;
	i = 0;
	while (node)
	{
		tkl = (t_tokens *)node->content;
		if (!ft_strcmp("|", tkl->token) && i == 0)
			return (msg_error_invalid_synax(tkl->token), 1);
		if (is_metachars(tkl->id_token) && !node->next && tkl->id_token != PIPE)
			return (msg_error_invalid_synax("newline"), 1);
		if (is_single_metachar(tkl->token, tkl->id_token, len_tokens))
			return (1);
		if (node->next)
			next = (t_tokens *)node->next->content;
		if (node->next && consecutive_metachars(tkl->token, next->token, \
			tkl->id_token, next->id_token))
			return (1);
		i++;
		node = node->next;
	}
	return (0);
}

int	parser(void)
{
	if (error_syntaxy_metachars(g_ms.tks, g_ms.len_tokens))
		return (1);
	reidentify_some_tokens(g_ms.tks);
	return (0);
}
