#include "../../include/minishell.h"


void	print_cmds(void)
{
	t_list		*node;
	t_commands	*cmd;
	// int			i;
	t_list		*cmd_builtins;
	// char 		*list_for_builtins;
	int			i;

	// i = 0;
	i = 0;
	// int count = ft_lstcount_nodes(g_ms.cmd_table);
	// node = g_ms.cmd_table;
	// while (i < count)
	// {
	// 	cmd = ((t_commands *)node->content);
	// 	// printf(YELLOW"cmd = %s\n"RESET, cmd->cmd_list[0]);
	// 	// printf(MAGENTA"path = %s\n"RESET, cmd->path);
	// 	// printf(MAGENTA"infd = %d\n"RESET, cmd->infd);
	// 	// printf(MAGENTA"outfd = %d\n"RESET, cmd->outfd);
	// 	node = node->next;
	// 	i++;
	// }
	node = g_ms.cmd_table;
	while (node)
	{
		cmd = ((t_commands *)node->content);
		cmd_builtins = (((t_commands *)node->content)->builtins_cmd_list);
		while (cmd_builtins)
		{
			printf(MAGENTA"cmd = %s\n"RESET, (char *)cmd_builtins->content);
			cmd_builtins = cmd_builtins->next;
		}
		// list_for_builtins = (cmd_builtins->builtins_cmd_list)->content;
		printf(YELLOW"cmd = %s\n"RESET, cmd->cmd_list[0]);
		printf(MAGENTA"path = %s\n"RESET, cmd->path);
		printf(MAGENTA"infd = %d\n"RESET, cmd->infd);
		printf(MAGENTA"outfd = %d\n"RESET, cmd->outfd);
		if(cmd->pipi_in == TRUE)
			printf("pipi_in\n");
		if(cmd->pipi_out == TRUE)
			printf("pipi_out\n");
		node = node->next;
		i++;
	}
}

void	init_fd_data(t_commands *cmd)
{
	cmd->infd = -6;
	cmd->outfd = -6;
	cmd->error_file = FALSE;
	cmd->rdc_out_app = FALSE;
	cmd->rdc_out = FALSE;
	cmd->rdc_in = FALSE;
	cmd->rdc_heredoc = FALSE;
}

void	init_data_executer(void)
{
	g_ms.num_pipes = count_id_token(PIPE);
	g_ms.num_cmds = g_ms.num_pipes + 1;
	g_ms.pid_fd = ft_calloc(g_ms.num_cmds, sizeof(int));
	g_ms.array_fd = ft_calloc(g_ms.num_pipes, sizeof(int *));
	get_cmd_data();
}

void	get_linked_list_builtins(t_commands *cmd)
{

	int	i;

	i = -1;
	while (cmd->cmd_list[++i])
		ft_lstadd_back(&cmd->builtins_cmd_list,
			ft_lstnew(cmd->cmd_list[i]));
}

void	get_cmd_data(void)
{
	t_list		*node;
	t_commands	*cmd;

	node = g_ms.tks;
	while (node)
	{
		cmd = ft_calloc(1, sizeof(t_commands));
		init_fd_data(cmd);
		get_cmds(cmd, node);
		get_envp(cmd);
		get_envp_path(cmd);
		get_path(cmd);
		get_linked_list_builtins(cmd);
		get_files_redirectors(node, cmd, &cmd->infd, &cmd->outfd);
		ft_lstadd_back(&g_ms.cmd_table, ft_lstnew(cmd));
		while (node && ((t_tokens *)node->content)->id_token != PIPE)
			node = node->next;
		if (node && ((t_tokens *)node->content)->id_token == PIPE)
			node = node->next;
	}
	print_cmds();
}
