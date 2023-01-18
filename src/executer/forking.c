#include "../../include/minishell.h"

void	check_fork(int i, t_list *node)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)node->content)->infd;
	outfd = ((t_commands *)node->content)->outfd;
	if (g_ms.pid_fd[i] < 0)
		exit(EXIT_FAILURE);
	if (g_ms.pid_fd[i] == 0)
	{
		if (infd == -1 || outfd == -1)
		{
			free_cmd_data();
			destroy_minishell();
			exit(EXIT_FAILURE);
		}
		child_process_check(node, i);
	}
}

void	forking(void)
{
	int		i;
	t_list	*node;

	i = 0;
	node = g_ms.cmd_table;
	if (g_ms.num_pipes == 0)
	{
		if (is_builtins(node) == TRUE)
		{
			execute_builtins(node, ((t_commands *)node->content)->outfd);
			return ;
		}
	}
	fd_memory_allocate();
	init_pipe_values();
	while (node)
	{
		g_ms.pid_fd[i] = fork();
		check_fork(i, node);
		i++;
		node = node->next;
	}
	close_pipes();
	wait_status();
	free_cmd_data();
}
