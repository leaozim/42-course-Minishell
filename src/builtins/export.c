#include "../../include/minishell.h"

int	update_strlen_to_quote_removal(char	*str)
{
	int	i;
	int	new_len;

	i = 0;
	new_len = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			if (count_quotes_pair(str, str[i], &i) == FALSE)
				return (-1);
			new_len++;
		}
		i++;
	}
	return (new_len);
}

int	*set_positions_quote_removal(char *str, int terminator)
{
	int	i;
	int	j;
	int	*positions;
	int	count;

	count = update_strlen_to_quote_removal(str);
	if (count == -1)
		return (NULL);
	positions = ft_calloc((count * 2) + 1, sizeof(int));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			positions[j] = i;
			j++;
			count_quotes_pair(str, str[i], &i);
			positions[j] = i;
			j++;
		}
		i++;
	}
	positions[j] = terminator;
	return (positions);
}

char	*quote_removal(char *str)
{
	int		*positions;
	char	*new_str;

	positions = set_positions_quote_removal(str, TERMINATOR);
	new_str = ft_strtrim_specific_pos(str, positions, TERMINATOR);
	free(positions);
	return (new_str);
}

t_bool	check_error_invalid_identifier(char *token)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strchr(token, '=') == NULL)
		while (token[++i])
			if (!ft_isalpha_underscore(token[i]))
				if ((token[0] != '\"') && (token[ft_strlen(token)] != '\"'))
					return (TRUE);
	i = ft_strchr_pos(token, '=');
	if (token[0] == '=')
		return (TRUE);
	while (j < i)
	{
		if (!ft_isalpha_underscore(token[0]))
			return (TRUE);
		if (!ft_isalpha_underscore(token[j]) && !ft_isdigit(token[j]))
			return (TRUE);
		j++;
	}
	return (FALSE);
}

//assuming that all quotes are enclosed
//mas e quando não houver "aspas" 'aspas' na parte depois do sinal de igual?
int	builtin_export(char *token)
{
	char	*str;

	str = quote_removal(token);
	if (check_error_invalid_identifier(str) == TRUE)
	{
		msg_error_not_a_valid_identifier(token, "export");
		return (free(str), EXIT_FAILURE);
	}
	ms.exit_status = 0;
	// ft_lstadd_back(&ms.env, ft_lstnew(token));
	// t_list *node;
	// node = ms.env;
	// node = ft_lstlast(node);
	// printf(RED"%s\n"RESET, (char *)node->content);
	return (free(str), EXIT_SUCCESS);
}
