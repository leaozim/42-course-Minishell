#include "../include/minishell.h"

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Argument list too long\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	is_erro_sintaxy_quotes(char *line)
{
	if (!is_valid_quoting(&line))
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Invalid quote syntax\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
