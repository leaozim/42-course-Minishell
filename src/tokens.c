#include "../include/minishell.h"

void	free_ptrs(char **str)
{
	int	i;

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
	char	*str;
	int		quotes;

	i = 0;
	str = list;
	quotes = 0; 
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			quotes = str[i];
			i++;
			while (str[i] && str[i] != quotes)
			{
				if (str[i] == original_value)
					str[i] = replaced_value;
				i++;
			}
			i++;
		}
		while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
			i++;
	}
}

void	tokens(int argc, char **argv)
{
	char	*arguments;
	char    **tokens;
	int     i;

	(void)argc;
	(void)argv;
	arguments = ft_strdup("echo ' oi ' p' humano  '");
	i = 0;
	// add_spaces(arguments);
	handle_quoting(arguments, SPACE, 48);

	tokens = ft_split(arguments, ' ');
	while (tokens[i])
	{
		handle_quoting(tokens[i], 48, SPACE);
	    printf("%d) tokens[%d] = %s\n", i, i, tokens[i]);
	    i++;
	}
	free_ptrs(tokens);
	free(arguments);
}




















