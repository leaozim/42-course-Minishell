#include "../../include/minishell.h"

void	executer(void)
{
	t_commands cmd;

	init_cmd_data(&cmd);
	free_expander(&cmd);
	// forking();
	// close_pipes();
	// wait_status();

	// free_ptrs(g_ms.cmd_data.path_envp);
	// free(g_ms.cmd_data.envp);
	// ft_free_int_array(g_ms.array_fd, g_ms.num_pipes + 1);
	// free(g_ms.pid_fd);
	// free(g_ms.cmd_data.tks);
}

//command and search execution

// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH

// echo -n > test2 > test3 oi ola | ls | grep obj > test1 | ls -l

//open close read
//access dup dup2
//execve fork pipe
//unlink wait waitpid
