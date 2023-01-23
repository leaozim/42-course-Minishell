/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:19:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			close_pipes();
			ft_lstclear(&g_ms.env, free);
			free_cmd_data();
			destroy_minishell();
			exit(EXIT_FAILURE);
		}
		child_process_check(node, i);
	}
}

t_bool	exec_commands(t_list *node)
{
	int	i;

	i = 0;
	if (g_ms.cmd_count > 0)
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
		return (TRUE);
	}
	return (FALSE);
}

void	forking(void)
{
	t_list	*node;

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
	if (exec_commands(node) == FALSE)
	{
		close_fds();
		free_cmd_data();
	}
}
