/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:48 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_redirection(int i)
{
	if (i == 0)
	{
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	}
	else if (i != g_ms.num_pipes)
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	}
	else
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
	}
}

void	child_dup_redirection(t_list *node, int i)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)node->content)->infd;
	outfd = ((t_commands *)node->content)->outfd;
	if (g_ms.num_pipes > 0)
	{
		pipe_redirection(i);
	}
	if (infd > 0)
		dup2(infd, STDIN_FILENO);
	if (outfd > 0)
		dup2(outfd, STDOUT_FILENO);
	close_pipes();
}

void	child_process_check(t_list *node, int i)
{
	char	*cmd;

	child_dup_redirection(node, i);
	if (check_path((t_commands *)node->content, node) == FALSE)
	{
		g_ms.exit_status = COMMAND_NOT_FOUND;
		cmd = ((t_commands *)node->content)->cmd_list[0];
		if (g_ms.exit_status != 0)
			msg_error_cmd_not_found(g_ms.exit_status, cmd);
		free_cmd_data();
		destroy_minishell();
		ft_lstclear(&g_ms.env, free);
		exit(g_ms.exit_status);
	}
	if (is_builtins(node) == TRUE)
	{
		execute_builtins(node, STDOUT_FILENO);
		close_pipes();
		free_cmd_data();
		ft_lstclear(&g_ms.env, free);
		destroy_minishell();
		exit(g_ms.exit_status);
	}
	else
		child_process_execution(node);
}

void	child_process_execution(t_list *node)
{
	char	*path;
	char	**cmds;
	char	**envp;

	path = ((t_commands *)node->content)->path;
	cmds = ((t_commands *)node->content)->cmd_list;
	envp = ((t_commands *)node->content)->envp;
	if (execve(path, cmds, envp) == -1)
	{
		free_cmd_data();
		destroy_minishell();
		ft_lstclear(&g_ms.env, free);
		exit(errno);
	}
}
