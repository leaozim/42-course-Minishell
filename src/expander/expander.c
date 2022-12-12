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

int	expand_check_next_character(char *token, int i, char **final_str)
{
	int isdigit;
	int start;
	int end;
	char *aux;
	char *expanded_var;

	isdigit = ft_isalpha_underscore(token[i + 1]);
	if (isdigit == TRUE) //colocar opcao "|| token[i + 1] == QUERY" quando tiver executor pronto
	{
		start = i;
		while ((token[i + 1] != SPACE) && (token[i + 1] != '\0') && (token[i + 1] != '\"') && (token[i + 1] != '$') && (token [i + 1] != '\''))
			i++;
		end = i;
		aux = ft_substr(token, (start + 1), (end - start));
		expanded_var = getenv(aux);
		if (expanded_var == NULL)
			expanded_var = "";
		ft_strupdate(final_str, ft_strjoin(*final_str, expanded_var));
		free(aux);
	}
	else
		ft_strupdate(final_str, ft_strjoin(*final_str, "$"));
	return (i);
}

char	*expand_variables(char *token)
{
	int		i;
	int		start;
	int		end;
	char	*aux;
	char	*final_str;

	i = 0;
	start = i;
	final_str = ft_strdup("");
	while (token[i])
	{
		if (ft_strchr(token, DOLLAR_SIGN) == NULL)
			return (free(final_str), token);
		if (token[i] == DOLLAR_SIGN)
		{
			end = i;
			aux = ft_substr(token, start, (end - start));
			ft_strupdate(&final_str, ft_strjoin(final_str, aux));
			free(aux);
			i = expand_check_next_character(token, i, &final_str);
			start = i + 1;
		}
		if (token[i + 1] == '\0')
		{
			end = i;
			aux = ft_substr(token, start, (end - start));
			ft_strupdate(&final_str, ft_strjoin(final_str, aux));
			free(aux);
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
	else if (*token == SQUOTE)
	{
		str = ft_strtrim(token, "'");
		return (str);
	}

	return (str);
	// envar = token;
	// envar++;
	// ptr = getenv(envar);
	// if (ptr == NULL)
	// 	return (NULL);
}
