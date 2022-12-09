#include "../include/minishell.h"
#include <unistd.h>

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		ft_putstr_fd("ERROR: Argument list too long\n", STDERR_FILENO);
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}

void	is_erro_sintaxy_quotes(char *line)
{
	if (!is_valid_quoting(&line))
	{
		ft_putstr_fd("ERROR: Invalid quote syntax\n", STDERR_FILENO);
		exit(1);
	}
}
