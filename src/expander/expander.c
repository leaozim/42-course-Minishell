#include "../../include/minishell.h"

void	expand_check_next_character(char *token, int *i, char **final_str)
{
	int		isdigit;
	int		start;
	char	*aux;
	char	*expanded_var;

	if (is_brace_expansion(token, i, final_str) == TRUE)
		return ;
	isdigit = ft_isalpha_underscore(token[*i + 1]);
	if (isdigit == TRUE) //colocar opcao "|| token[i + 1] == QUERY"
	{
		start = *i;
		while (ft_isalpha_underscore(token[*i + 1]))
			*i += 1;
		aux = ft_substr(token, (start + 1), (*i - start));
		expanded_var = getenv(aux);
		free(aux);
		if (expanded_var == NULL)
			expanded_var = "";
		ft_strupdate(final_str, ft_strjoin(*final_str, expanded_var));
	}
	else
		ft_strupdate(final_str, ft_strjoin(*final_str, "$"));
}

int	check_last_expansion_occurence(char *token)
{
	int	i;

	i = ft_strrchr_pos(token, DOLLAR_SIGN); //error: command not found when not expansible $_
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
	char	*envar;
	char	*final_str;

	i = 0;
	start = i;
	final_str = ft_strdup("");
	while (token[i])
	{
		if (token[i] == DOLLAR_SIGN)
		{
			if (check_last_expansion_occurence(token) != 0)
				expander_get_substrs(token, start, i, &final_str);
			envar = is_envar_expansible(token, &i, &final_str);
			if (envar != NULL)
				return (envar);
			start = i + 1;
		}
		if (i == check_last_expansion_occurence(token))
		{
			expander_get_substrs(token, i + 1, ft_strlen(token), &final_str);
			break ;
		}
		i++;
	}
	return (final_str);
}

char	*cases_that_are_not_expansible(char *token)
{
	if (token[0] == SQUOTE)
		return (ft_strtrim(token, "\'"));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL && *token == DQUOTES)
		return (ft_strtrim(token, "\""));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL)
		return (ft_strdup(token));
	return (NULL);
}

char	*shell_expansion(char *token)
{
	char	*str;

	str = cases_that_are_not_expansible(token);
	if (str != NULL)
		return (str);
	str = expand_variables(token);
	if (*token == DQUOTES)
		return (ft_strupdate(&str, ft_strtrim(str, "\"")), str);
	return (str);
}

void	expander(void)
{
	char			*temp;
	t_lst_tokens	*tklist;
	t_list			*node;

	node = ms.tks;
	while (node)
	{
		tklist = (t_lst_tokens *)node->content;
		temp = shell_expansion(tklist->token);
		free(tklist->token);
		tklist->token = temp;
		node = node->next;
	}
}
