#include "../../include/minishell.h"
#include <readline/readline.h>
#include <signal.h>

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		printf("\n");
		free(line);
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
}

void    handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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
