#include "../../include/minishell.h"

void	check_fork(int i, t_list *node)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)g_ms.cmd_table->content)->infd;
	outfd = ((t_commands *)g_ms.cmd_table->content)->outfd;
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
	fd_memory_allocate();
	init_pipe_values();
	while (node)
	{
		if (is_builtins(node) == TRUE)
		{
			execute_builtins(node);
		}
		else
		{
			g_ms.pid_fd[i] = fork();
			check_fork(i, node);
		}
		node = node->next;
		i++;
	}
}
