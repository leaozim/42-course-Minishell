#include "../../include/minishell.h"

void	init_fd_data(t_commands *cmd)
{
	cmd->infd = -6;
	cmd->outfd = -6;
	// cmd->error_file = FALSE;
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

t_arguments	*create_argv_content(char *argv, int index)
{
	t_arguments	*content;

	content = ft_calloc(1, sizeof(t_arguments));
	content->argv = argv;
	content->id_argv = index;
	return (content);
}

void	get_linked_list_argv(t_commands *cmd)
{
	int	i;

	i = -1;
	while (cmd->argv[++i])
		ft_lstadd_back(&cmd->argv_list,
			ft_lstnew(create_argv_content(cmd->argv[i], cmd->id[i])));
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
		get_argv(cmd, node);
		get_linked_list_argv(cmd);
		get_linked_list_builtins(cmd);
		get_files_redirectors(cmd, &cmd->infd, &cmd->outfd);
		ft_lstadd_back(&g_ms.cmd_table, ft_lstnew(cmd));
		while (node && ((t_tokens *)node->content)->id_token != PIPE)
			node = node->next;
		if (node && ((t_tokens *)node->content)->id_token == PIPE)
			node = node->next;
	}
}