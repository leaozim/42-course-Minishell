/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_executer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:40 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:19:41 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_data(t_commands *cmd, t_list *node)
{
	cmd->infd = -6;
	cmd->outfd = -6;
	cmd->rdc_out_app = FALSE;
	cmd->rdc_out = FALSE;
	cmd->rdc_in = FALSE;
	cmd->rdc_heredoc = FALSE;
	get_cmds(cmd, node);
	get_envp(cmd);
	get_envp_path(cmd);
	get_path(cmd);
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->path));
}

void	init_data_executer(void)
{
	g_ms.sig = 0;
	g_ms.num_pipes = count_id_token(PIPE);
	g_ms.num_cmds = g_ms.num_pipes + 1;
	g_ms.pid_fd = ft_calloc(g_ms.num_cmds, sizeof(int));
	g_ms.array_fd = ft_calloc(g_ms.num_pipes, sizeof(int *));
	get_cmd_data();
}

void	get_cmd_data(void)
{
	t_list		*node;

	node = g_ms.tks;
	g_ms.cmd_table = NULL;
	g_ms.free_me = NULL;
	while (node)
	{
		g_ms.cmd = ft_calloc(1, sizeof(t_commands));
		g_ms.cmd->argv_list = NULL;
		g_ms.cmd->envp_path = NULL;
		init_data(g_ms.cmd, node);
		get_argv(g_ms.cmd, node);
		get_linked_list_argv(g_ms.cmd);
		get_linked_list_builtins(g_ms.cmd);
		ft_lstadd_back(&g_ms.free_me, ft_lstnew(g_ms.cmd));
		if (g_ms.cmd_table != NULL)
			ft_lstadd_back(&g_ms.free_me, ft_lstnew(g_ms.cmd_table));
		get_files_redirectors(g_ms.cmd, &g_ms.cmd->infd, &g_ms.cmd->outfd);
		ft_lstadd_back(&g_ms.cmd_table, ft_lstnew_free_me(g_ms.cmd));
		while (node && ((t_tokens *)node->content)->id_token != PIPE)
			node = node->next;
		if (node && ((t_tokens *)node->content)->id_token == PIPE)
			node = node->next;
	}
	ft_lstclear(&g_ms.free_me, NULL);
}
