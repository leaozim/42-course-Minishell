#include "../../include/minishell.h"

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
