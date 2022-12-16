#include "../../include/minishell.h"
#include "defines.h"
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
	int		isdigit;
	int		start;
	int		end;
	char	*aux;
	char	*expanded_var;

	if (token[*i + 1] == '{')
	{
		*i = *i + 2;
		start = *i;
		while(ft_isalpha_underscore(token[*i]))
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
	while (ft_isalpha_underscore(token[i + 1]) || token[i + 1] == '{')
		i++;
	if (token[i + 1] == '}')
		i++;
	return (i);
}

t_bool is_envar_expansible(char *token)
{
	if (token[0] == SQUOTE)
		return (FALSE);
	return (TRUE);
}

// void	cases_where_variable_is_not_expansible(char *token)
// {
	
// }

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

	final_str = ft_strdup("");
	last_dollar_occurence = check_last_position(token);

	if (ft_strchr(token, DOLLAR_SIGN) == NULL)
	{
		free(final_str);
		return (token);
	}
	while (token[i])
	{
		if (token[i] == DOLLAR_SIGN)
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

	if (token[0] == SQUOTE)
	{
		str = ft_strtrim(token, "\'");
		return(str);
	}

	str = expand_variables(token);

	if (ft_strchr(token, DOLLAR_SIGN) == NULL && *token == DQUOTES)
	{
		str = ft_strtrim(token, "\"");
		return (str);
	}

	if (*token == DQUOTES)
	{
		ft_strupdate(&str, ft_strtrim(str, "\""));
		return(str);
	}
	return(str);

}
