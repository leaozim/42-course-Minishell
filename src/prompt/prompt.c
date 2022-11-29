#include "../../include/minishell.h"

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		free(line);
		printf("\n");
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
