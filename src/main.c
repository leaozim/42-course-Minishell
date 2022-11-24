#include "../include/minishell.h"

int	main(int argc, char **argv)
{
	// char		*line_terminal;
	t_minishell	ms;

	(void)argv;
	check_arguments(argc);
	init_minishell(&ms);
	while (TRUE)
	{
		ms.prompt_line = creat_prompt();
		is_erro_sintaxy_quotes(ms.prompt_line);
		tokens(&ms);
		free(ms.prompt_line);
	}
	return (EXIT_SUCCESS);
}
