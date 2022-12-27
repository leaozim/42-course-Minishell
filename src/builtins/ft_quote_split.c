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
	printf(YELLOW"%d - str[%d]: %c\n"RESET, *count, *i, str[*i]);
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
				return(count);
			}
		}
		while (str[i] == c && i != (int)ft_strlen(str))
			i++;
	}
	return (count);
}

int	assign_words(char *str, char c, int *i)
{
	while (str[*i] != c)
	{
		if (str[*i] == SQUOTE || str[*i] == DQUOTES)
		{
			break ;
		}
		if (*i == (int)ft_strlen(str))
		{
			return(1);
		}
		*i += 1;
	}
	return (0);
}

int	assign_quoted_words(char *str, int *i)
{
	if (count_quotes_pair(str, str[*i], i) == FALSE)
	{
		return (1);
	}
	*i += 1;
	return (0);
}

char	**split_assign_values(char *str, char c, int count)
{
	int	i;
	int	j;
	int	start;
	int	end;
	char	**table;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	table = ft_calloc(count + 1, sizeof(char *));
	while (str[i] == c && i != (int)ft_strlen(str))
		i++;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			start = i;
			assign_quoted_words(str, &i);
			end = i;
			table[j] = ft_substr(str, start, end - start); ///////PEGANDO AQUI
			printf(BLUE"s: |%d| e: |%d| i:|%d| table[%d]: %s\n"RESET, start, end, i, j, table[j]);
			j++;
		}
		if (str[i] != c)
		{
			start = i;
			if (assign_words(str, c, &i) == 1)
			{
				end = i;
				if (start == end)
					break ;
				table[j] = ft_substr(str, start, end - start);
				j++;
				table[j] = NULL;
				return (table);
			}
			end = i;
			if (start != end)
			{
				table[j] = ft_substr(str, start, end - start);
				j++;
			}
		}
		while (str[i] == c && i != (int)ft_strlen(str))
			i++;
	}
	if (count == 0)
		printf(YELLOW"s: |%d| e: |%d| i:|%d|\n"RESET, start, end, i); //tirar
	table[j] = NULL;
	return (table);
}

char	**ft_quote_split(char *str, char c)
{
	int		count;
	char	**table;

	count = split_count_words(str, c);
	table = split_assign_values(str, c, count);
	return (table);
}