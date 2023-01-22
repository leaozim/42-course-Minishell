#include "../../include/minishell.h"

void	close_fds(void)
{
	t_list		*node;
	t_commands	*cmd;
	int			i;

	i = 3;
	while (!close(i))
		i++;
	node = g_ms.cmd_table;
	while (node)
	{
		cmd = node->content;
		if (cmd->infd > 0)
			close(cmd->infd);
		if (cmd->outfd > 0)
			close(cmd->outfd);
		node = node->next;
	}
}

void	close_pipes(void)
{
	int			i;

	i = 0;
	close_fds();
	if (g_ms.num_pipes > 0)
	{
		while (i < g_ms.num_pipes)
		{
			close(g_ms.array_fd[i][0]);
			close(g_ms.array_fd[i][1]);
			i++;
		}
	}
}
