#include "../include/minishell.h"

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		free(line);
		printf("\n");
		exit(EXIT_FAILURE);
	}
}

void	creat_prompt(void)
{
	char	*line;

	line = readline(PROMPT);
	add_history(line);
	check_prompt(line);
	if (!is_valid_quoting(&line))
		exit(1);
	free(line);
}
