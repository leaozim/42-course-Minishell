#include "../include/minishell.h"

int	event(void)
{
	return (0);
}

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
	destroy_ctrl_c();
	redisplay_prompt(g_ms.sig);
	exit(130);
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_clear_history();
	// rl_done = TRUE;
	// rl_event_hook = event;
	// ft_putchar_fd('\n', STDOUT_FILENO);
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, redisplay_prompt);
}
