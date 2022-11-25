#include "../include/minishell.h"
#include <sys/wait.h>

t_bool	is_valid_quoting(char **list)
{
	int		i;
	int		value;
	char	*str;

	i = 0;
	str = *list;
	value = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			value = str[i];
			i++;
			while (str[i] && str[i] != value)
				i++;
			if (str[i] == '\0')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	replace_value_inside_quotes(char *list, int old_value, int new_value)
{
	char	*str;
	int		quotes;
	int		i;

	i = 0;
	str = list;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			quotes = str[i];
			i++;
			while (str[i] && str[i] != quotes)
			{
				if (str[i] == old_value)
					str[i] = new_value;
				i++;
			}
			i++;
		}
		while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
			i++;
	}
}

int	count_tokens_specific(char *str)
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
		{
			value = str[i];
			i++;
			while (str[i] && str[i] != value)
				i++;
			if (str[i] == value)
				qtt_tokens += 1; 
		}
		else if (str[i] == PIPE)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN && str[i + 1] == RDRCT_IN)
		{
			qtt_tokens += 1;
			i++;
		}
		else if (str[i] == RDRCT_OU && str[i + 1] == RDRCT_OU)
		{
			qtt_tokens += 1;
			i++;
		}
		else if (str[i] == RDRCT_OU)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN)
		{
			qtt_tokens += 1;
		}
		i++;
	}
	return (qtt_tokens);
}


t_bool	check_for_specific_token(char c)
{
	if (c == RDRCT_IN || \
		c == RDRCT_OU || \
		c == PIPE || \
		c == SQUOTE || \
		c == DQUOTES)
		return (TRUE);
	return (FALSE);
}

int	check_qtt_to_be_incremented(char *line)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	if (line[i] == SQUOTE || line[i] == DQUOTES)
	{
		value = line[i];
		i++;
		while (line[i] && line[i] != value)
			i++;
		i++;
	}
	else if (line[i] == RDRCT_IN && line[i + 1] == RDRCT_IN)
		i += 2;
	else if (line[i] == RDRCT_OU && line[i + 1] == RDRCT_OU)
		i += 2;
	else
		i++;
	return (i);
}

char	*add_spaces_specific_tokens(char *line, int count)
{
	char	*str;
	int		value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(1, ft_strlen(line) + (count * 2) + 1);
	while (line[i])
	{
		if (check_for_specific_token(line[i]) == TRUE)
		{
			str[j] = SPACE;
			j++;
			value = check_qtt_to_be_incremented(&line[i]);
			while (value--)
				str[j++] = line[i++];
			str[j] = SPACE;
			j++;
		}
		else
			str[j++] = line[i++];
	}
	return (str);
}

int 	check_len_tab(char **str)
{
	int	i;

	i = 0;
	char **aux = str;
	while (aux[i])
		i++;
	return (i);
}

int		*identify_tokens(char **str, int len_tab)
{
	int	i;
	int	*id_tks;
	char *aux;

	i = 0;
	id_tks = ft_calloc(len_tab, sizeof(int));
	while (i < len_tab)
	{
		aux = str[i];
		if (aux[0] == DQUOTES || aux[0] == SQUOTE)
			id_tks[i] = aux[0];
		else if (ft_strlen(aux) == 1)
			id_tks[i] = aux[0];
		else if (aux[0] == RDRCT_IN && ft_strlen(aux) == 2)
			id_tks[i] = HEREDOC;
		else if (aux[0] == RDRCT_OU && ft_strlen(aux) == 2)
			id_tks[i] = APPEND;
		else
			id_tks[i]= 5;
		i++;
	}
	return (id_tks);
}

void	creat_tokens(t_minishell *ms, t_tokens *tokens)
{
	char	**tab_tokens;
	int		*tab_id;
	t_lexer	lx;
	int		i;

	(void)tokens;
	lx.str_spcs = "\0";
	lx.qtt_tokens = 0;
	lx.len_tab = 0;

	replace_value_inside_quotes(ms->prompt_line, SPACE, 48);
	lx.qtt_tokens = count_tokens_specific(ms->prompt_line);
	lx.str_spcs = add_spaces_specific_tokens(ms->prompt_line, lx.qtt_tokens);
	tab_tokens = ft_split(lx.str_spcs, ' ');
	lx.len_tab = check_len_tab(tab_tokens);
	tab_id = identify_tokens(tab_tokens, lx.len_tab);

	i = 0;
	while (i < lx.qtt_tokens)
	{
		replace_value_inside_quotes(tab_tokens[i], 48, SPACE);
		printf("%d) tab_tokens[%d] = %s\n", i, i, tab_tokens[i]);
		i++;
	}
	i = 0;
	while (i < lx.len_tab)
	{
		printf("%d) tab_id[%d] = %i\n", i, i, tab_id[i]);
		i++;
	}
	free_ptrs(tab_tokens);
	free(tab_id);
	free(lx.str_spcs);
}
