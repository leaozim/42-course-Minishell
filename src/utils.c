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

void	is_erro_sintaxy_quotes(char *line)
{
	if (!is_valid_quoting(line))
		exit(1);
}
