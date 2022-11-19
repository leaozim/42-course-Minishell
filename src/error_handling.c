#include "minishell.h"

void	check_program(int argc)
{
	if (argc > 1)
	{
		printf("Error! Argument list too long\n");
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}
