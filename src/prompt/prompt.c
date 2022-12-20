#include "../../include/minishell.h"
#include <unistd.h>

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		free(line);
		exit(EXIT_FAILURE);
	}
}

char	*create_prompt(void)
{
	char	*line;

	line = readline(PROMPT);
	check_prompt(line);
	add_history(line);
	return (line);
}
