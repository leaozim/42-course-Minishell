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

void	handle_quoting(char *list, int original_value, int replaced_value)
{
	size_t	i;
	char	*str;
	int		quotes;

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
				if (str[i] == original_value)
					str[i] = replaced_value;
				i++;
			}
			i++;
		}
	while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
			i++;
	}
}

int	count_tokens(char *str)
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
		else if (str[i] == GREATERTHAN)
			qtt_tokens += 1;
		else if (str[i] == LESSTHAN)
		{
			qtt_tokens += 1;
		}
		i++;
	}
	return (qtt_tokens);
}

void	tokens(int argc, char **argv)
{
	char	*arguments;
	char	**tokens;
	int		i;

	(void)argc;
	(void)argv;
	arguments = ft_strdup("echo>>>' oi  '? $ p ' humano  | '|");
	i = 0;
	handle_quoting(arguments, SPACE, 48);
	// count_tokens(arguments);
	printf("%d\n", count_tokens(arguments));
	tokens = ft_split(arguments, ' ');
	while (tokens[i])
	{
		handle_quoting(tokens[i], 48, SPACE);
		printf("%d) tokens[%d] = %s\n", i, i, tokens[i]);
		i++;
	}
	free_ptrs(tokens);
	free(arguments);
}
