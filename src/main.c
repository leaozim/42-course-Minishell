#include "../include/minishell.h"

int	main(int argc, char **argv)
{
	// char	*line_terminal;

	(void)argv;
	check_arguments(argc);
	tokens(argc, argv);
	// while (TRUE)
	// {
	// 	line_terminal = creat_prompt();
	// 	is_erro_sintaxy_quotes(line_terminal);
	
	// 	free(line_terminal);
	// }
	return (EXIT_SUCCESS);
}
