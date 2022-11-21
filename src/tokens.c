#include "../include/minishell.h"

void    free_ptrs(char **str)
{
	int    i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	handle_quoting(char *list, int original_value, int replaced_value)
{
	size_t	i;
	char	*aux;
	int		quotes;

	i = 0;
	aux = list;
	quotes = 0; 
	while (aux[i])
	{
		if (aux[i] == SQUOTE || aux[i] == DQUOTES)
		{
			quotes = aux[i];
			i++;
			while (aux[i] && aux[i] != quotes)
			{
				if (aux[i] == original_value)
					aux[i] = replaced_value;
				i++;
			}
			i++;
		}
		while (aux[i] && aux[i] != SQUOTE && aux[i] != DQUOTES)
		{
			i++;
		}
	}
}

void    tokens(int argc, char **argv)
{
	char    *arguments;
	// char    **tokens;
	// int     i;

	(void)argc;
	(void)argv;
	arguments = ft_strdup(" \"ou \" ");
	// i = 0;
	// add_spaces(arguments);
	handle_quoting(arguments, SPACE, 48);
	// tokens = ft_split(arguments, TEMP);
	// while (tokens[i])
	// {
	//     printf("%d) tokens[%d] = %s\n", i, i, tokens[i]);
	//     i++;
	// }
	// free_ptrs(tokens);
	free(arguments);
}




















