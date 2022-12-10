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

char	*case_double_quotes(char *token)
{
	int		i;
	int		start;
	int		end;
	int		isdigit;
	char	*aux;
	char	*final_str;
	char	*expanded_var;

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
			isdigit = ft_isalpha_underscore(token[i + 1]);
			if (isdigit == TRUE) //colocar opcao "|| token[i + 1] == QUERY" quando tiver executor pronto
			{
				start = i;
				while ((token[i + 1] != SPACE) && (token[i + 1] != '\0') && (token[i + 1] != '\"'))
					i++;
				end = i;
				aux = ft_substr(token, (start + 1), (end - start));
				if ((expanded_var = getenv(aux)) == NULL)
					expanded_var = "";
				ft_strupdate(&final_str, ft_strjoin(final_str, expanded_var));
				free(aux);
			}
			else
				ft_strupdate(&final_str, ft_strjoin(final_str, "$"));
			start = i + 1;
		}
		i++;
	}
	// printf("ANTES:  "BLUE"|"RESET"\"oi $HOME $*$ $ tudo $$ $OLDPWD $? ?$\""BLUE"|\n"RESET);
	// printf("DEPOIS: "GREEN"|"RESET"%s"GREEN"|\n"RESET, final_str);
	return (final_str);
}

//"\"oi $HOME $*$ $ tudo $$ $OLDPWD $? ?$\""
//oi /home/etomiyos $ $ tudo $$ /home/etomiyos/42projetos $? ?$

char	*expander(char *token)
{
	char	*envar;
	char	*ptr;
	char	*aux;

	if (!token)
		return (NULL); //checagem de erros (fazer mais)

	if (*token == DQUOTES)
	{
		aux = case_double_quotes(token);
		free(aux);
	}

	//1) checar quantos $ tem
	//2) expandir e pegar o resultado para saber o tamanho da
	//string total que vou retornar


	//echo "oi $HOME   tudo  $OLDPWD $$ ?$"

	//FAZER POR ÚLTIMO. se for aspas simples, basta remover as aspas
	if (*token == SQUOTE)
	{
		aux = ft_strtrim(token, "'");
		return (aux);
	}

	envar = token;
	envar++;
	ptr = getenv(envar);
	if (ptr == NULL)
		return (NULL);
	return (ptr);

	//caso das aspas duplas
}
