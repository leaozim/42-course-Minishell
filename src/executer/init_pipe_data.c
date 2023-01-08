#include "../../include/minishell.h"

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
