/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_metachars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_metachars(int id_tks)
{
	if (id_tks == HEREDOC || \
		id_tks == APPEND || \
		id_tks == RDRCT_IN || \
		id_tks == RDRCT_OU || \
		id_tks == PIPE)
		return (TRUE);
	return (FALSE);
}

int	consecutive_metachars(char *token, char *next_token, int id, int next_id)
{
	if (is_metachars(id))
	{
		if (is_metachars((next_id)) && id != PIPE)
		{
			if (id != PIPE)
				msg_error_invalid_synax(next_token);
			else
				msg_error_invalid_synax(token);
			return (1);
		}
		else if (id == PIPE && next_id == PIPE)
			return (msg_error_invalid_synax(token), 1);
	}
	return (0);
}

int	is_single_metachar(char *token, int id, int len_tokens)
{
	if (is_metachars(id) && len_tokens == 1)
		return (msg_error_invalid_synax(token), 1);
	return (0);
}
