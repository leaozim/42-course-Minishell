#include "minishell.h"

int	main(int argc, char **argv)
{
	check_program(argc);
	tokens(argc, argv);
	// while (TRUE)
	// {
	// 	creat_prompt();
	// }
	return (EXIT_SUCCESS);
}
