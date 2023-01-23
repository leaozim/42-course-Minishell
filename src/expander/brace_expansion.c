/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brace_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:09 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msg_error_bad_substitution(char *token)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd(": bad substitution\n", STDERR_FILENO);
}

char	*cases_that_are_not_expansible(char *token)
{
	if (token[0] == SQUOTE)
		return (ft_strtrim(token, "\'"));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL && *token == DQUOTES)
		return (ft_strtrim(token, "\""));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL)
		return (ft_strdup(token));
	return (NULL);
}

void	update_index_next_character_after_brace(int *i, char *token)
{
	while (*i < ((int)ft_strlen(token) - 1))
	{
		if (ft_isalpha_underscore(token[*i]))
			*i += 1;
		else
			return ;
	}
}

static void	brace_expansion(char *token, int start, int *i, char **final_str)
{
	char	*expanded_var;
	int		end;
	char	*aux;

	if (token[*i] == '}' && token[*i - 1] != '{')
	{
		end = *i;
		aux = ft_substr(token, start, (end - start));
		expanded_var = getenv(aux);
		free(aux);
		if (expanded_var == NULL)
			expanded_var = "";
		ft_strupdate(final_str, ft_strjoin(*final_str, expanded_var));
		return ;
	}
	else
	{
		msg_error_bad_substitution(token);
		return ;
	}
}

t_bool	is_brace_expansion(char *token, int *i, char **final_str)
{
	int		start;
	int		len;

	len = ft_strlen(token);
	if (token[*i + 1] == '{' && len == 2)
	{
		msg_error_bad_substitution(token);
		return (TRUE);
	}
	if (token[*i + 1] == '{' && len > 2)
	{
		*i = *i + 2;
		start = *i;
		update_index_next_character_after_brace(i, token);
		brace_expansion(token, start, i, final_str);
		return (TRUE);
	}
	return (FALSE);
}
