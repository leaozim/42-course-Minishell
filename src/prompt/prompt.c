#include "../../include/minishell.h"

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		dprintf(2, "\n");
		free(line);
		rl_clear_history();
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
