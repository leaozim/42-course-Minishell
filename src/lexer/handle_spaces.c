#include "../../include/minishell.h"
#include <readline/chardefs.h>

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

char	*add_characters_in_specific_position(char *line, int index, char characters)
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
			str[j++] = characters;
		str[j] = line[i];
		j++;
		i++;
	}
	free(line);
	return (str);
}

char	*add_marcador(char *line)
{
	int		i;
	t_bool	is_two_quotes;
	int		quotes;

	i = 0;
	while (line[i])
	{
		is_two_quotes = FALSE;
		if (line[i] == SQUOTE || line[i] == DQUOTES)
		{
			quotes = line[i];
			i++;
			while (line[i] && line[i] != quotes)
				i++;
			i++;
			if (line[i] == SQUOTE || line[i] == DQUOTES)
				is_two_quotes = TRUE;
		}
		if (is_two_quotes == TRUE)
		{
			line = add_characters_in_specific_position(ms.prompt_line, i, 'l');
		}
		i++;
	}
	return (line);
}