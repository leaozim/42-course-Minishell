#include "../include/minishell.h"

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		printf("Error! Argument list too long\n");
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}

t_bool	is_valid_quoting(char *list)
{
	int		i;
	int		value;
	char	*str;

	i = 0;
	str = list;
	value = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			value = str[i];
			i++;
			while (str[i] && str[i] != value)
				i++;
			if (str[i] == '\0')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
