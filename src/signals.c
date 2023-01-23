/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:04 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:37:46 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redisplay_prompt(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_ms.exit_status = 130;
	}
}

void	signal_break_heredoc(int signal)
{
	(void)signal;
	close(g_ms.fd_heredoc);
	ft_putchar_fd('\n', STDOUT_FILENO);
	destroy_heredoc();
	redisplay_prompt(g_ms.sig);
	exit(130);
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, redisplay_prompt);
}
