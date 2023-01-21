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
	g_ms.sig = SIGINT;
	close(g_ms.fd_heredoc);
	ft_putchar_fd('\n', STDOUT_FILENO);
	destroy_heredoc(g_ms.aux_cmd);
	exit(130);
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, redisplay_prompt);
}
