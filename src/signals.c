#include "../include/minishell.h"
#include <readline/readline.h>

void	signal_break_heredoc(int signal)
{
	
	(void)signal;
	write(2, "\n", 1);
	// dprintf(2,);
	ft_lstclear(&ms.tks, free);
	exit(130);
}

void	redisplay_prompt(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, redisplay_prompt);
}