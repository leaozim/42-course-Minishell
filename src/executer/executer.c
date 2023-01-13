#include "../../include/minishell.h"

void	close_fds(void)
{
	int	i;

	i = 3;
	while (!close(i))
		i++;
}

void	executer(void)
{
	init_data_executer();
	forking();
	close_pipes();
	close_fds();
	wait_status();
	free_cmd_data();
}

// print_cmds();

//command and search execution

// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH

// echo -n > test2 > test3 oi ola | ls | grep obj > test1 | ls -l
