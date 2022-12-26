#include "../../include/minishell.h"
#include "defines.h"

void	msg_error_not_a_valid_identifier(char *token, char *cmd)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(" `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	ms.exit_status = 1;
}

int	count_quotes_pair(char	*str, char c, int *i)
{
	*i += 1;
	while (str[*i] != c)
	{
		if (*i == (int)ft_strlen(str) && str[*i] != c)
			return (FALSE);
		*i += 1;
	}
	return (TRUE);
}

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

int	*set_positions_quote_removal(char *str)
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
	positions[j] = -1;
	return (positions);
}

size_t	ft_intarray_len(int *array, int terminator)
{
	int	i;

	i = 0;
	while (array[i] != terminator)
		i++;
	return (i);
}

char	*ft_strtrim_specific_positions(char *str, int *positions)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	dest = ft_calloc((ft_strlen(str) - ft_intarray_len(positions, -1)) + 1, sizeof(char));
	i = 0;
	j = 0;
	k = 0;
	while (i < (int)ft_strlen(str))
	{
		while (i == positions[k])
		{
			i++;
			k++;
		}
		dest[j] = str[i];
		j++;
		i++;
	}
	printf("%s\n", dest);
	return (dest);
}

char	*quote_removal(char *str)
{
	int		*positions;
	char	*new_str;

	positions = set_positions_quote_removal(str);
	new_str = ft_strtrim_specific_positions(str, positions);
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
	i = ft_strrchr_pos(token, '=');
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
