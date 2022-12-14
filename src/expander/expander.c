#include "../../include/minishell.h"
#include <readline/chardefs.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>

void ft_strupdate(char **str, char *newstr)
{
	char	*temp;

	temp = *str;
	*str = newstr;
	free(temp);
}

void	expand_check_next_character(char *token, int *i, char **final_str)
{
	int isdigit;
	int start;
	int end;
	char *aux;
	char *expanded_var;

	isdigit = ft_isalpha_underscore(token[*i + 1]);
	if (isdigit == TRUE) //colocar opcao "|| token[i + 1] == QUERY" quando tiver executor pronto
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
	while (ft_isalpha_underscore(token[i + 1]))
		i++;
	return (i);
}

t_bool is_envar_expansible(char *token)
{
	if (token[0] == SQUOTE)
		return (FALSE);
	return (TRUE);
}

char	*expand_variables(char *token)
{
	int		i;
	int		last_dollar_occurence;
	int		start;
	int		end;
	char	*aux;
	char	*final_str;

	i = 0;
	start = i;

	if (token[0] == SQUOTE)
	{
		final_str = ft_strtrim(token, "\'");
		return(final_str);
	}

	final_str = ft_strdup("");
	last_dollar_occurence = check_last_position(token);

	if (ft_strchr(token, DOLLAR_SIGN) == NULL)
		return (free(final_str), token);
	while (token[i])
	{
		if (token[i] == DOLLAR_SIGN) //"'$SHELL'"
		{
			if (check_last_position(token) != 0)
			{
				end = i;
				aux = ft_substr(token, start, (end - start));
				ft_strupdate(&final_str, ft_strjoin(final_str, aux));
				free(aux);
			}
			if (is_envar_expansible(final_str) == TRUE)
				expand_check_next_character(token, &i, &final_str);
			else
			{
				start = i;
				while (ft_isalpha_underscore(token[i + 1]))
					i++;
				end = i;
				aux = ft_substr(token, start, (end - start + 1));
				return (aux);
			}
			start = i + 1;
		}
		if (i == last_dollar_occurence)
		{
			start = i + 1;
			aux = ft_substr(token, start, (ft_strlen(token) - start));
			ft_strupdate(&final_str, ft_strjoin(final_str, aux));
			free(aux);
			break ;
		}
		i++;
	}
	return (final_str);
}

char	*expander(char *token)
{
	char	*str;

	str = expand_variables(token);
	if (*token == DQUOTES)
	{
		str = ft_strtrim(str, "\"");
		return(str);
	}

	return(str);
}
