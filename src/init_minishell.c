/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:58 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:20:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_minishell(char **argv, char **envp)
{
	(void)argv;
	g_ms.tab_tokens = NULL;
	g_ms.tab_id = NULL;
	g_ms.tks = NULL;
	g_ms.env = NULL;
	g_ms.len_tokens = 0;
	g_ms.exit_status = 0;
	create_env(envp);
}
