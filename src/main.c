#include "../include/minishell.h"

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
