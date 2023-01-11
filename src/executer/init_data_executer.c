#include "../../include/minishell.h"

void	init_data_executer(void)
{
	g_ms.num_pipes = count_id_token(PIPE);
	g_ms.num_cmds = g_ms.num_pipes + 1;
	g_ms.array_fd = ft_calloc(g_ms.num_pipes, sizeof(int *));
	g_ms.pid_fd = ft_calloc(g_ms.num_cmds, sizeof(int));
}
