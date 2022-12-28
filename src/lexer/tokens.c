#include "../../include/minishell.h"

// int	count_operators(char *str, char c, int *i, int *count);

// int	count_quotes_pair(char	*str, char c, int *i)
// {
// 	if (*i == ((int)ft_strlen(str) - 1))
// 	{
// 		ft_putstr_fd("Minishell: ", STDERR_FILENO);
// 		ft_putstr_fd("ERROR: Invalid quoting syntax\n", STDERR_FILENO);
// 		return (0);
// 	}
// 	*i += 1;
// 	if (str[*i] == c)
// 		return (0);
// 	while (str[*i] != c)
// 	{
// 		if (*i == (int)ft_strlen(str) - 1)
// 		{
// 			return (0);
// 		}
// 		*i += 1;
// 	}
// 	if (*i != ((int)ft_strlen(str) - 1)) //check next character after enclosing quote
// 	{
// 		if (str[*i + 1] == DQUOTES || str[*i + 1] == SQUOTE)
// 		{
// 			*i += 1;
// 			count_quotes_pair(str, c, i);
// 		}
// 	}
// 	if (str[*i + 1] != SPACE && !ft_isops(str[*i + 1]))
// 	{
// 		while((str[*i] != SQUOTE || str[*i] != DQUOTES) && !ft_isops(str[*i]) && *i != (int)ft_strlen(str) - 1)
// 			*i += 1;
// 	}
// 	return (TRUE);
// }

// int	count_quoted_words(char	*str, char c, int *i, int *count)
// {
// 	int	pair;

// 	pair = count_quotes_pair(str, str[*i], i);
// 	if (pair == 0)
// 		return (1);
// 	if (ft_isops(str[*i]))
// 	{
// 		*count += 1;
// 		count_operators(str, SPACE, i, count);
// 	}
// 	*i += 1;
// 	*count += 1;
// 	(void)c;
// 	return (0);
// }

// int	count_operators(char *str, char c, int *i, int *count)
// {
// 	while (str[*i] != DQUOTES && str[*i] != SQUOTE && str[*i] != c)
// 	{
// 		if (*i == (int)ft_strlen(str))
// 		{
// 			return (1);
// 		}
// 		else if (str[*i] == RDRCT_IN && str[*i + 1] == RDRCT_IN)
// 		{
// 			*count += 1;
// 			*i += 1;
// 		}
// 		else if (str[*i] == RDRCT_OU && str[*i + 1] == RDRCT_OU)
// 		{
// 			*count += 1;
// 			*i += 1;
// 		}
// 		else if (str[*i] == RDRCT_IN)
// 		{
// 			*count += 1;
// 		}
// 		else if (str[*i] == RDRCT_OU)
// 			*count += 1;
// 		else if (str[*i] == PIPE)
// 			*count += 1;
// 		*i += 1;
// 	}
// 	return (0);
// }

// int	count_words(char *str, char c, int *i, int *count)
// {
// 	while (str[*i] != c)
// 	{
// 		if (*i == (int)ft_strlen(str) || ft_strlen(str) == 1)
// 		{
// 			*count += 1;
// 			return (1);
// 		}
// 		if (ft_isops(str[*i])) //&& diferente de espaço
// 		{
// 			if (*i > 1 && str[*i - 1] != c)
// 			{
// 				*count += 1;
// 			}
// 			if (count_operators(str, c, i, count) == 1)
// 			{
// 				*count += 1;
// 				return (1);
// 			}
// 		}
// 		if (str[*i] == SQUOTE || str[*i] == DQUOTES)
// 		{
// 			return (0);
// 		}
// 		*i += 1;
// 	}
// 	*count += 1;
// 	return (0);
// }

// int	split_count_words(char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while(str[i] == c && i != (int)ft_strlen(str))
// 		i++;
// 	while (str[i])
// 	{
// 		if (ft_isops(str[i]))
// 		{
// 			if (count_operators(str, c, &i, &count) == 1)
// 				return (count);
// 		}
// 		if (str[i] == SQUOTE || str[i] == DQUOTES)
// 		{
// 			if (count_quoted_words(str, c, &i, &count) == 1)
// 				return (count);
// 		}
// 		else if (str[i] != c)
// 		{
// 			if (count_words(str, c, &i, &count) == 1)
// 				return (count);
// 		}
// 		while (str[i] == c && i != (int)ft_strlen(str))
// 			i++;
// 	}
// 	return (count);
// }

// int	assign_words(char *str, char c, int *i)
// {
// 	while (str[*i] != c)
// 	{
// 		if (str[*i] == SQUOTE || str[*i] == DQUOTES)
// 			break ;
// 		if (*i == (int)ft_strlen(str))
// 			return(1);
// 		*i += 1;
// 	}
// 	return (0);
// }

// int	assign_quoted_words(char *str, int *i)
// {
// 	if (count_quotes_pair(str, str[*i], i) == FALSE)
// 		return (1);
// 	*i += 1;
// 	return (0);
// }

// char	**split_assign_values(char *str, char c, int count)
// {
// 	int		i;
// 	int		j;
// 	int		start;
// 	int		end;
// 	char	**table;

// 	i = 0;
// 	j = 0;
// 	start = 0;
// 	end = 0;
// 	table = ft_calloc(count + 1, sizeof(char *));
// 	while (str[i] == c && i != (int)ft_strlen(str))
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i] == SQUOTE || str[i] == DQUOTES)
// 		{
// 			start = i;
// 			if (assign_quoted_words(str, &i) == 1)
// 			{
// 				table[j] = NULL;
// 				return (table);
// 			}
// 			end = i;
// 			table[j] = ft_substr(str, start, end - start);
// 			// printf(BLUE"s: |%d| e: |%d| i:|%d| table[%d]: %s\n"RESET, start, end, i, j, table[j]);
// 			j++;
// 		}
// 		if (str[i] != c)
// 		{
// 			start = i;
// 			if (assign_words(str, c, &i) == 1)
// 			{
// 				end = i;
// 				if (start == end)
// 					break ;
// 				table[j] = ft_substr(str, start, end - start);
// 				j++;
// 				table[j] = NULL;
// 				return (table);
// 			}
// 			end = i;
// 			if (start != end)
// 			{
// 				table[j] = ft_substr(str, start, end - start);
// 				j++;
// 			}
// 		}
// 		while (str[i] == c && i != (int)ft_strlen(str))
// 			i++;
// 	}
// 	table[j] = NULL;
// 	return (table);
// }

// char	**ft_quote_split(char *str, char c)
// {
// 	int		count;
// 	char	**table;

// 	count = split_count_words(str, c);
// 	table = split_assign_values(str, c, count);
// 	return (table);
// }

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
			qtt_tokens_quotes(value, str, &i, &qtt_tokens);
		else if (str[i] == PIPE)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN && str[i + 1] == RDRCT_IN)
			qtt_tokens_heredoc_or_append(&i, &qtt_tokens);
		else if (str[i] == RDRCT_OU && str[i + 1] == RDRCT_OU)
			qtt_tokens_heredoc_or_append(&i, &qtt_tokens);
		else if (str[i] == RDRCT_OU)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN)
			qtt_tokens += 1;
		// else if(str[i] == MARKER)
		// 	qtt_tokens += 1;
		i++;
	}
	return (qtt_tokens);
}

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
		else if (ft_strlen(aux) == 1)
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

void	create_tokens(void)
{
	char	*str_with_spcs;
	int		qtt_tokens;

	if (ms.prompt_line ==  NULL)
		return ;
	ms.prompt_line = add_marker(ms.prompt_line);
	replace_value_inside_quotes(ms.prompt_line, SPACE, REPLACE_VALUE);
	qtt_tokens = count_tokens_specific(ms.prompt_line);
	str_with_spcs = add_spaces_specific_tokens(ms.prompt_line, qtt_tokens);
	ms.tab_tokens = ft_split(str_with_spcs, ' ');
	// ms.tab_tokens = ft_quote_split(ms.prompt_line, SPACE);
	ms.len_tokens = check_len_tab(ms.tab_tokens);
	reverse_replace(ms.tab_tokens, ms.len_tokens);
	ms.tab_id = identify_tokens(ms.tab_tokens, ms.len_tokens);
	create_token_list(ms.tab_tokens, ms.tab_id, ms.len_tokens);
	free(str_with_spcs);
}
