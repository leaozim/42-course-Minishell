#include "../include/minishell.h"

int	main(int argc, char **argv)
{
	(void)argv;
	check_arguments(argc);
	// tokens(argc, argv);
	while (TRUE)
	{
		creat_prompt();
	}
	return (EXIT_SUCCESS);
}
