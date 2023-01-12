#include "../../include/minishell.h"

void	check_fork(int i, t_list *node)
{
	if (g_ms.pid_fd[i] < 0)
		exit(EXIT_FAILURE);
	if (g_ms.pid_fd[i] == 0)
	{
		// if (g_ms.infd == -1 && i == 0)
		// {
		// 	free_commands(); //talvez tirar
		// 	exit(EXIT_FAILURE);
		// }
		child_process_check(node);
	}
}

void	forking(void)
{
	t_list	*node;
	int	i;

	i = 0;
	//init_fd_data (check_open_files)
	fd_memory_allocate();
	init_pipe_values();
	node = g_ms.cmd_table;
	while (node)
	{
		if(is_builtins() == TRUE)
			execute_builtins(node); 
		else
		{
			g_ms.pid_fd[i] = fork();
			check_fork(i, node);
		};
		node = node->next;
		i++;
	}
	// while (g_ms.cmd_data.node)
	// {
	// 	get_cmd_data(); //split_cmd
	// 	check_open_files(g_ms.tks, &g_ms.infd, &g_ms.outfd);
	// 	g_ms.pid_fd[i] = fork();
	// 	fork_check(i);
	// 	free_commands();
	// 	i++;
	// }
}
