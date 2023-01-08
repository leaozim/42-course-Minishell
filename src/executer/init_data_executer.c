#include "../../include/minishell.h"

void	init_static_cmd_data(void)
{
	g_ms.cmd_data.node = g_ms.tks;
	g_ms.cmd_data.path_envp = NULL;
	g_ms.cmd_data.tklist = (t_tokens *)g_ms.cmd_data.node->content;
	g_ms.cmd_data.tklist->index = 0;
	g_ms.len_pipes = count_id_token(PIPE);
}

void	init_dynamic_cmd_data(void)
{
	g_ms.array_fd = ft_calloc(g_ms.len_pipes, sizeof(int *));
	g_ms.pid_fd = ft_calloc(g_ms.len_pipes + 1, sizeof(int));
	get_envp();
	split_envp_path();
}

void	init_cmd_data(void)
{
	init_static_cmd_data();
	init_dynamic_cmd_data();
}