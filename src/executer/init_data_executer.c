#include "../../include/minishell.h"

static void	init_static_cmd_data(void)
{
	g_ms.cmd_data.path_envp = NULL;
	g_ms.cmd_data.node = g_ms.tks;
	g_ms.cmd_data.tklist = (t_tokens *)g_ms.cmd_data.node->content;
	g_ms.cmd_data.tklist->index = 0;
	g_ms.len_pipes = count_id_token(PIPE);
}

static void	init_dynamic_cmd_data(void)
{
	g_ms.array_fd = ft_calloc(g_ms.len_pipes, sizeof(int *));
	g_ms.pid_fd = ft_calloc(g_ms.len_pipes + 1, sizeof(int));
	get_envp();
	split_envp_path();
}

void	fd_memory_allocate(void)
{
	int	i;

	i = 0;
	while (i < g_ms.len_pipes)
	{
		g_ms.array_fd[i] = ft_calloc(2, sizeof(int));
		i++;
	}
}

void	init_pipe_values(void)
{
	int	i;
	int value;

	i = 0;
	value = -5;
	while (i < g_ms.len_pipes)
	{
		value = pipe(g_ms.array_fd[i]);
		if (value == -1)
			perror("pipe:");
		i++;
	}
}

void	init_cmd_data(void)
{
	init_static_cmd_data();
	init_dynamic_cmd_data();
}
