/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:06 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	wait_status(void)
{
	int		i;

	i = 0;
	while (i < g_ms.num_cmds)
	{
		waitpid(g_ms.pid_fd[i], (int *)&g_ms.exit_status, 0);
		if (WIFEXITED(g_ms.exit_status))
			g_ms.exit_status = WEXITSTATUS(g_ms.exit_status);
		i++;
	}
}
