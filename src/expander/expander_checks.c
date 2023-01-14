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
	if (isdigit == TRUE || token[*i + 1] == QUERY) //colocar opcao "|| token[i + 1] == QUERY"
	{
		start = *i;
		while (ft_isalpha_underscore(token[*i + 1]))
			*i += 1;
		if (ft_strchr(token, QUERY) != NULL) //comeca
		{
			start = ft_strchr_pos(token, QUERY);
			if (ft_strlen(token) == 2)
			{
				ft_strupdate(final_str, ft_itoa(g_ms.exit_status));
				return ;
			}
			while (ft_isalpha_underscore(token[*i + 1]))
				*i += 1;
			aux = ft_substr(token, start + 1, (*i - start));
			expanded_var = ft_itoa(g_ms.exit_status);
			ft_strupdate(final_str, ft_strjoin(expanded_var, aux));
			free(aux);
			free(expanded_var);
			return ;
		} //termina
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

int	check_last_expansion_occurrence(char *token)
{
	int	i;

	i = ft_strrchr_pos(token, DOLLAR_SIGN);
	while (ft_isalpha_underscore(token[i + 1]) || token[i + 1] == '{' || token[i + 1] == QUERY)
		i++;
	if (token[i + 1] == '}')
		i++;
	return (i);
}

t_bool	is_envar_between_squote(char *token)
{
	if (token[0] == SQUOTE)
		return (TRUE);
	return (FALSE);
}

char	*is_envar_expansible(char *token, int *i, char **final_str)
{
	int		start;
	int		end;
	char	*aux;

	if (is_envar_between_squote(*final_str) == FALSE)
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
