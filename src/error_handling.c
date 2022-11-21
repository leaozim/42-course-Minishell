#include "../include/minishell.h"

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		printf("Error! Argument list too long\n");
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}

t_bool   is_valid_quoting(char **list)
{
	int		i;
	int		value;
	char	*aux;

	i = 0;
	aux = *list;
	value = 0;
	while (aux[i])
	{
		if (aux[i] == SQUOTE || aux[i] == DQUOTES)
		{
			value = aux[i];
			i++;
			while (aux[i] && aux[i] != value)
				i++;
			if (aux[i] == '\0')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}


