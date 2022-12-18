#include "../../include/minishell.h"

void	ft_strupdate(char **str, char *newstr)
{
	char	*temp;

	temp = *str;
	*str = newstr;
	free(temp);
}

void	expand_check_next_character(char *token, int *i, char **final_str)
{
	int		isdigit;
	int		start;
	int		end;
	char	*aux;
	char	*expanded_var;

	if (token[*i + 1] == '{')
	{
		*i = *i + 2;
		start = *i;
		while (ft_isalpha_underscore(token[*i]))
			*i += 1;
		if (token[*i] == '}')
		{
			end = *i;
			aux = ft_substr(token, start, (end - start));
			expanded_var = getenv(aux);
			free(aux);
			if (expanded_var == NULL)
				expanded_var = "";
			ft_strupdate(final_str, ft_strjoin(*final_str, expanded_var));
			dprintf(2, MAGENTA"%d %c\n"RESET, *i, token[*i]);
			return ;
		}
		else
		{
			dprintf(2, "bash: %s: bad substitution\n", token);
			return ;
		}
	}
	isdigit = ft_isalpha_underscore(token[*i + 1]);
	if (isdigit == TRUE) //colocar opcao "|| token[i + 1] == QUERY"
	{
		start = *i;
		while (ft_isalpha_underscore(token[*i + 1]))
			*i += 1;
		end = *i;
		aux = ft_substr(token, (start + 1), (end - start));
		expanded_var = getenv(aux);
		free(aux);
		if (expanded_var == NULL)
			expanded_var = "";
		ft_strupdate(final_str, ft_strjoin(*final_str, expanded_var));
	}
	else
		ft_strupdate(final_str, ft_strjoin(*final_str, "$"));
}

int	check_last_position(char *token)
{
	int	i;

	i = ft_strrchr_pos(token, DOLLAR_SIGN);
	while (ft_isalpha_underscore(token[i + 1]) || token[i + 1] == '{')
		i++;
	if (token[i + 1] == '}')
		i++;
	return (i);
}

t_bool	is_envar_between_squote(char *token)
{
	if (token[0] == SQUOTE)
		return (FALSE);
	return (TRUE);
}

char	*is_envar_expansible(char *token, int *i, char **final_str)
{
	int		start;
	int		end;
	char	*aux;

	if (is_envar_between_squote(*final_str) == TRUE)
		expand_check_next_character(token, i, final_str);
	else
	{
		start = *i;
		while (ft_isalpha_underscore(token[*i + 1]))
			*i += 1;
		end = *i;
		aux = ft_substr(token, start, (end - start + 1));
		return (aux);
	}
	return (NULL);
}

void	expander_get_substrs(char *token, int start, int end, char **final_str)
{
	char	*aux;

	aux = ft_substr(token, start, (end - start));
	ft_strupdate(final_str, ft_strjoin(*final_str, aux));
	free(aux);
}


char	*expand_variables(char *token)
{
	int		i;
	int		start;
	char	*final_str;
	char	*envar;

	i = 0;
	start = i;
	final_str = ft_strdup("");
	if (ft_strchr(token, DOLLAR_SIGN) == NULL)
		return (free(final_str), ft_strdup(token));
	while (token[i])
	{
		if (token[i] == DOLLAR_SIGN)
		{
			if (check_last_position(token) != 0)
				expander_get_substrs(token, start, i, &final_str);
			envar = is_envar_expansible(token, &i, &final_str);
			if (envar != NULL)
				return (envar);
			start = i + 1;
		}
		if (i == check_last_position(token))
		{
			expander_get_substrs(token, i + 1, ft_strlen(token), &final_str);
			break ;
		}
		i++;
	}
	return (final_str);
}

char	*expanding_tokens(char *token)
{
	char	*str;

	if (token[0] == SQUOTE)
		return (ft_strtrim(token, "\'"));
	str = expand_variables(token);
	if (ft_strchr(token, DOLLAR_SIGN) == NULL && *token == DQUOTES)
		return (ft_strupdate(&str, ft_strtrim(token, "\"")), str);
	if (*token == DQUOTES)
		return (ft_strupdate(&str, ft_strtrim(str, "\"")), str);
	return (str);
}

void	expander(void)
{
	char		*temp;
	t_tokens	*tokens;
	t_list		*node;

	node = ms.tks;
	while (node)
	{
		tokens = (t_tokens *)node->content;
		temp = expanding_tokens(tokens->tokens);
		free(tokens->tokens);
		tokens->tokens = temp;
		node = node->next;
	}
}
