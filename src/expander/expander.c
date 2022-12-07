#include "../../include/minishell.h"
#include <readline/chardefs.h>
#include <stddef.h>
#include <stdlib.h>

// "$EDITOR"
//=> "nano"
# define TOKENS_ENVAR_GENERAL "bar$EDITOR"
//=> "barnano"

//export foo=42
# define TOKENS_ENVAR_SQUOTE_1 "'$foo'"
//=> "'$foo'"

# define TOKENS_ENVAR_SQUOTE_2 "baz$foo'bar'"
//=> "baz42'bar'"

# define TOKENS_ENVAR_SQUOTE_3 "baz$foo'$foo'"
//=> "baz42'$foo'"

# define TOKENS_ENVAR_DQUOTES_1 "\"$foo\""
//=> "\"42\""

# define TOKENS_ENVAR_DQUOTES_2 "baz$foo\"$foo\""
//=> "baz42\"42\""

# define TOKENS_ENVAR_MIXED_QUOTES_1 "baz$foo\"$foo'\""
//=> "baz42\"42'\""

# define TOKENS_ENVAR_MIXED_QUOTES_2 "\"baz$foo'$foo'\""
//=> "\"baz42'42'\""

# define TOKENS_ENVAR_MIXED_QUOTES_3 "'baz$foo'$foo''"
//=> "'baz$foo'42''"

//foo=42
# define TOKENS_ENVAR_LOCAL_1 "$foo"
// => "42"

# define TOKENS_ENVAR_LOCAL_2 "bar$foo"
// => "bar42"


// int	how_many_dollar_signs(char *token)
// {
// 	size_t	i;
// 	size_t	len;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	len = ft_strlen(token);
// 	while (i < len)
// 	{
// 		if (token[i] == DOLLAR_SIGN)
// 			if ((token[i + 1] != SPACE) && (token[i + 1] != '\0') && (token[i + 1] != '\"'))
// 				count++;
// 		//no caso de "$$$$"
// 		if ((token[i] == DOLLAR_SIGN) && (token[i + 1] == DOLLAR_SIGN))
// 			i++;
// 		i++;
// 	}
// 	return (count);
// }

char	*case_double_quotes(char *token)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	isdigit;
	char	*aux;
	char	*final_str;
	char	*expanded_var;

	i = 0;
	len = ft_strlen(token);
	start = i + 1;
	final_str = ft_strdup("");
	while (i < len)
	{
		if (token[i] == DOLLAR_SIGN)
		{
			isdigit = ft_isalpha_underscore(token[i + 1]);
			end = i;
			aux = ft_substr(token, start, (end - start));
			final_str = ft_strjoin(final_str, aux);
			if (isdigit == 1) //colocar opcao "|| token[i + 1] == QUERY" quando tiver executor pronto
			{
				start = i;
				while ((token[i + 1] != SPACE) && (token[i + 1] != '\0') && (token[i + 1] != '\"'))
					i++;
				end = i;
				aux = ft_substr(token, (start + 1), (end - start));
				// printf("%s", aux);
				expanded_var = getenv(aux);
				final_str = ft_strjoin(final_str, expanded_var);
			}
			else {
				final_str = ft_strjoin(final_str, "$");
			}
			start = i + 1;
		}
		i++;
	}
	// printf(GREEN"|"RESET"%s"GREEN"|\n"RESET, final_str);
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
		return (NULL);

	if (*token == DQUOTES)
	{
		case_double_quotes(token);
	}

	// expand_variables();
	// lenght_of_expanded_string()

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
