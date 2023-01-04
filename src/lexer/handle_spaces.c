#include "../../include/minishell.h"
#include <stddef.h>
#include <stdio.h>

int	check_qtt_to_be_incremented(char *line, char *full_line)
{
	int	value;
	int	i;
	// int	qtt_quotes;

	i = 0;
	value = 0;
	(void)full_line;
	if (line[i] == SQUOTE || line[i] == DQUOTES)
	{
		value = line[i];
			i++;
		while (line[i] && line[i] != value)
		{
			i++;
		}
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
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	str = ft_calloc(1, ft_strlen(line) + (count * 2) + 1);
	while (i < ft_strlen(line))
	{
		if (check_for_specific_token(line[i]) == TRUE)
		{
			str[j] = SPACE;
			j++;
			value = check_qtt_to_be_incremented(&line[i], line);
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

void	replace_value_inside_quotes(char *list, int old_vle, int new_vle)
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
				if (str[i] == old_vle)
					str[i] = new_vle;
				i++;
			}
			i++;
		}
		while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
			i++;
	}
}

char	*add_characters_in_specific_position(char *line, int index, char charac)
{
	int		j;
	int		i;
	char	*str;

	j = 0;
	i = 0;
	str = ft_calloc(1, ft_strlen(line) + 2);
	while (i < (int)ft_strlen(line) + 1)
	{
		if (j == index)
			str[j++] = charac;
		str[j] = line[i];
		j++;
		i++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}

char	*add_marker(char *line)
{
	t_bool	is_two_quotes;
	int		quotes;
	int		i;
	
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		is_two_quotes = FALSE;
		if (line[i] == SQUOTE || line[i] == DQUOTES)
		{
			quotes = line[i];
			i++;
			while (line[i] && line[i] != quotes)
				i++;
			if (line[i])
				i++;
			if ((line[i] && line[i] != ' ' && line[i] != '\0'))
				is_two_quotes = TRUE;
		}
		else if (i > 0)
		{
			if (line[i] != ' ' && (line[i + 1] == '\"' || line[i + 1] == '\''))
			{
				is_two_quotes = TRUE;
				i++;
			}
		}
		if (is_two_quotes == TRUE)
			line = add_characters_in_specific_position(line, i, MARKER);
		i++;
	}
	return (line);
}
