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
		ms.prompt_line = create_prompt();

		printf(CYAN"\nTOKENS\n"RESET);

		is_erro_sintaxy_quotes(ms.prompt_line);
		tokens(&ms);

		//EXPANDER
		printf(CYAN"\nEXPANDER\n"RESET);
		char *str = expander("$DDOIDERA");
		if (str != NULL)
			printf("%s\n", str);

		free(ms.prompt_line);
	}
	return (EXIT_SUCCESS);
}
