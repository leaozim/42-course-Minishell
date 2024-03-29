/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:30 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	check_for_specific_token(char c)
{
	if (c == RDRCT_IN || \
		c == RDRCT_OU || \
		c == PIPE || \
		c == SQUOTE || \
		c == DQUOTES || \
		c == MARKER)
		return (TRUE);
	return (FALSE);
}

int	check_len_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	g_ms.len_tokens = i;
	return (i);
}

void	qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens)
{
	value = line[*i];
		*i += 1;
	while (line[*i] && line[*i] != value)
		*i += 1;
	if (line[*i] == value)
		*qtt_tokens += 1;
}

void	reverse_replace(char **table_tokens, int len_tab)
{
	int	i;

	i = -1;
	while (len_tab > ++i)
		replace_value_inside_quotes(table_tokens[i], REPLACE_VALUE, SPACE);
}

int	qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens)
{
	*qtt_tokens += 1;
	*i += 1;
	return (*qtt_tokens);
}
