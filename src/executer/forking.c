#include "../../include/minishell.h"

void	check_fork(int i, t_list *node)
{
	char		**cmds;
	t_commands	*cmd;

	cmd = (t_commands *)node->content;
	cmds = cmd->cmd_list;
	if (g_ms.pid_fd[i] < 0)
		exit(EXIT_FAILURE);
	if (g_ms.pid_fd[i] == 0)
	{
		if (cmd->infd == -1 || cmd->outfd == -1)
		{
			free_cmd_data();
			destroy_minishell();
			exit(EXIT_FAILURE);
		}
		if (cmds[0] == NULL)
		{
			ft_lstclear(&g_ms.tks, destroy_t_tokens);
			free(g_ms.tab_tokens);
			free(g_ms.tab_id);
			ft_lstclear(&g_ms.env, free);
			ft_free_int_array(g_ms.array_fd, g_ms.num_pipes);
			free(g_ms.pid_fd);
			ft_lstclear(&g_ms.cmd_table, destroy_t_commands);
			exit(g_ms.exit_status);
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
		if (is_builtins(node) == TRUE && \
		((t_commands *)node->content)->error_file == FALSE)
		{
			execute_builtins(node, ((t_commands *)node->content)->outfd);
			free_cmd_data();
			return ;
		}
	}
	if (g_ms.num_cmds > 0)
	{
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
}
