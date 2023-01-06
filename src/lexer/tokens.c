#include "../../include/minishell.h"

int	*identify_tokens(char **str, int len_tab)
{
	int		i;
	int		*id_tks;
	char	*aux;

	i = 0;
	id_tks = ft_calloc(len_tab, sizeof(int));
	while (i < len_tab)
	{
		aux = str[i];
		if (aux[0] == DQUOTES || aux[0] == SQUOTE)
			id_tks[i] = aux[0];
		if (ft_strlen(aux) == 1)
			id_tks[i] = aux[0];
		else if (aux[0] == RDRCT_IN && ft_strlen(aux) == 2)
			id_tks[i] = HEREDOC;
		else if (aux[0] == RDRCT_OU && ft_strlen(aux) == 2)
			id_tks[i] = APPEND;
		else
			id_tks[i] = COMMAND;
		i++;
	}
	return (id_tks);
}

int	count_specific_tokens(char *str)
{
	int	i;
	int	value;
	int	qtt_tokens;

	i = 0;
	value = 0;
	qtt_tokens = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
			qtt_tokens_quotes(value, str, &i, &qtt_tokens);
		else if (str[i] == PIPE)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN && str[i + 1] == RDRCT_IN)
			qtt_tokens_heredoc_or_append(&i, &qtt_tokens);
		else if (str[i] == RDRCT_OU && str[i + 1] == RDRCT_OU)
			qtt_tokens_heredoc_or_append(&i, &qtt_tokens);
		else if (str[i] == RDRCT_OU || str[i] == RDRCT_IN)
			qtt_tokens += 1;
		else if (str[i] == MARKER)
			qtt_tokens += 1;
		i++;
	}
	return (qtt_tokens);
}

int	set_true_quotes(char *line, int *i)
{
	int		quotes;

	if (line[*i] == SQUOTE || line[*i] == DQUOTES)
	{
		quotes = line[*i];
		*i += 1;
		while (line[*i] && line[*i] != quotes)
			*i += 1;
		if (line[*i])
			*i += 1;
		if ((line[*i] && line[*i] != ' ' && line[*i] != '\0' && \
			line[*i] != PIPE && line[*i] != RDRCT_IN && line[*i] != RDRCT_OU))
			return (1);
	}
	else if (*i > 0)
	{
		if (line[*i] != ' ' && (line[*i + 1] == '\"' || line[*i + 1] == '\'')
			&& (line[*i] != PIPE && line[*i] != RDRCT_IN
				&& line[*i] != RDRCT_OU))
		{
			*i += 1;
			return (1);
		}
	}
	return (0);
}

char	*add_marker(char *line)
{
	t_bool	is_two_quotes;
	int		i;

	i = 0;
	while (i < (int)ft_strlen(line))
	{
		is_two_quotes = FALSE;
		if (set_true_quotes(line, &i))
			is_two_quotes = TRUE;
		if (is_two_quotes == TRUE)
			line = add_chrs_in_specific_position(line, i, MARKER);
		i++;
	}
	return (line);
}

void	create_tokens(void)
{
	char	*str_with_spcs;
	int		qtt_tokens;

	ms.prompt_line = add_marker(ms.prompt_line);
	replace_value_inside_quotes(ms.prompt_line, SPACE, REPLACE_VALUE);
	qtt_tokens = count_specific_tokens(ms.prompt_line);
	str_with_spcs = add_spaces_specific_tokens(ms.prompt_line, qtt_tokens);
	ms.tab_tokens = ft_split(str_with_spcs, ' ');
	check_len_tab(ms.tab_tokens);
	reverse_replace(ms.tab_tokens, ms.len_tokens);
	ms.tab_id = identify_tokens(ms.tab_tokens, ms.len_tokens);
	create_token_list(ms.tab_tokens, ms.tab_id, ms.len_tokens);
	free(str_with_spcs);
}
