#include "../../include/minishell.h"

void	expander_get_offsets(char *token, int start, int end, char **final_str)
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

	i = -1;
	start = 0;
	final_str = ft_strdup("");
	while (token[++i])
	{
		if (token[i] == DOLLAR_SIGN)
		{
			if (check_last_expansion_occurrence(token) != INDEX_ZERO)
				expander_get_offsets(token, start, i, &final_str);
			envar = is_envar_expansible(token, &i, &final_str);
			if (envar != NULL)
				return (envar);
			start = i + 1;
		}
		if (i == check_last_expansion_occurrence(token))
			expander_get_offsets(token, i + 1, ft_strlen(token), &final_str);
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

char	*minishell_expansion(char *token)
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
	t_tokens		*tklist;
	t_list			*node;

	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		temp = minishell_expansion(tklist->token);
		free(tklist->token);
		tklist->token = temp;
		node = node->next;
	}
}
