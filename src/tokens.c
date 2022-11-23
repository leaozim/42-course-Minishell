#include "../include/minishell.h"

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

void	count_tokens_specific(char *str, int qtt_tokens)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
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
		else if (str[i] == PIPE  || str[i] == GREATERTHAN || str[i] == LESSTHAN)
			qtt_tokens += 1;
		else if (str[i] == LESSTHAN && str[i + 1] == LESSTHAN)
		{
			qtt_tokens += 1;
			i++;
		}
		else if (str[i] == GREATERTHAN && str[i + 1] == GREATERTHAN)
		{
			qtt_tokens += 1;
			i++;
		}
		i++;
	}
}

t_bool	check_for_specific_token(char c)
{
	if (c == LESSTHAN || \
		c == GREATERTHAN || \
		c == PIPE || \
		c == SQUOTE || \
		c == DQUOTES)
		return (TRUE);
	return (FALSE);
}

int	check_qtt_to_be_incremented(char *arg)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	if (arg[i] == SQUOTE || arg[i] == DQUOTES)
	{
		value = arg[i];
		i++;
		while (arg[i] && arg[i] != value)
			i++;
		i++;
	}
	else if (arg[i] == LESSTHAN && arg[i + 1] == LESSTHAN)
		i += 2;
	else if (arg[i] == GREATERTHAN && arg[i + 1] == GREATERTHAN)
		i += 2;
	else
		i++;
	return (i);
}

char	*add_spaces_at_specific_tokens(char *arg, int count)
{
	char	*str;
	int		value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(1, ft_strlen(arg) + (count * 2) + 1);
	while (arg[i])
	{
		if (check_for_specific_token(arg[i]) == TRUE)
		{
			str[j] = SPACE;
			j++;
			value = check_qtt_to_be_incremented(&arg[i]);
			while (value--)
				str[j++] = arg[i++];
			str[j] = SPACE;
			j++;
		}
		else
			str[j++] = arg[i++];
	}
	return (str);
}

void	tokens(t_minishell *ms)
{
	char	**tokens;
	char	*str_with_spaces;
	int		i;

	// echo<' oi  '?$p' humano  | '|>>
	i = 0;
	replace_value_inside_quotes(ms->prompt_line, SPACE, 48);
	count_tokens_specific(ms->prompt_line, ms->qtt_tokens);
	str_with_spaces = add_spaces_at_specific_tokens(ms->prompt_line, ms->qtt_tokens);
	tokens = ft_split(str_with_spaces, ' ');
	while (tokens[i])
	{
		replace_value_inside_quotes(tokens[i], 48, SPACE);
		printf("%d) tokens[%d] = %s\n", i, i, tokens[i]);
		i++;
	}
	free_ptrs(tokens);
	free(str_with_spaces);
}
