/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:20:04 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fd_memory_allocate(void)
{
	int	i;

	i = 0;
	while (i < g_ms.num_pipes)
	{
		g_ms.array_fd[i] = ft_calloc(2, sizeof(int));
		i++;
	}
}

void	init_pipe_values(void)
{
	int	i;
	int	value;

	i = 0;
	value = -5;
	while (i < g_ms.num_pipes)
	{
		value = pipe(g_ms.array_fd[i]);
		if (value == -1)
			perror("pipe:");
		i++;
	}
}
