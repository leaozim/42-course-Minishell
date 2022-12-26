#include "../../include/minishell.h"

int	count_quotes_pair(char	*str, char c, int *i)
{
	*i += 1;
	if (*i == (int)ft_strlen(str) || str[*i] == c)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Invalid quoting syntax\n", STDERR_FILENO);
		return (FALSE);
	}
	while (str[*i] != c)
	{
		if (*i == (int)ft_strlen(str))
		{
			return (FALSE);
		}
		*i += 1;
	}
	return (TRUE);
}

int	count_quoted_words(char	*str, int *i, int *count)
{
	if (count_quotes_pair(str, str[*i], i) == FALSE)
	{
		return (1);
	}
	*count += 1;
	*i += 1;
	return (0);
}

int	count_words(char *str, char c, int *i, int *count)
{
	while (str[*i] != c)
	{
		if (str[*i] == SQUOTE || str[*i] == DQUOTES)	//
			break ;										//ou return
		if (*i == (int)ft_strlen(str))
		{
			*count += 1;
			return (1);
		}
		*i += 1;
	}
	*count += 1;
	return (0);
}

int	split_count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while(str[i] == c && i != (int)ft_strlen(str))
		i++;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
			count_quoted_words(str, &i, &count); //transformar em void e mudar nome da fn para update index
		else if (str[i] != c)
		{
			if (count_words(str, c, &i, &count) == 1)
			{
				// printf(BLUE"\nFINAL: "RESET "str[%d]: %c | %d\n", i, str[i], count);
				return(count);
			}
		}
		while(str[i] == c && i != (int)ft_strlen(str))
			i++;
	}
	return (count);
}

// char	**split_assign_values(char *str, char c, int count)
// {
// 	char	**table;

// 	table = ft_calloc(count + 1, sizeof(char *));

// }

char	**ft_quote_split(char *str, char c)
{
	int		count;
	// char	**table;

	count = split_count_words(str, c);
	(void)count;
	return(NULL);
	// table = split_assign_values(str, c);
	// return (table);
}