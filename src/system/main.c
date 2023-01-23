/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:00 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:52:31 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_minishell	g_ms;

void	repl(void)
{
	while (TRUE)
	{
		g_ms.prompt_line = create_prompt();
		create_tokens();
		expander();
		if (!g_ms.tks || parser() == 1)
		{
			destroy_minishell();
			rl_redisplay();
			continue ;
		}
		join_tokens(&g_ms.tks);
		reidentify_some_tokens(g_ms.tks);
		executer();
		destroy_minishell();
	}
	ft_lstclear(&g_ms.env, free);
}

int	main(int argc, char **argv, char **envp)
{
	check_arguments(argc);
	init_minishell(argv, envp);
	handle_signal();
	repl();
	return (g_ms.exit_status);
}
