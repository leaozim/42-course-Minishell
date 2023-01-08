#include "../include/minishell.h"

// void is_error(char *prompt_line)
// {
// 	if (is_erro_sintaxy_quotes(g_ms.prompt_line))
// 		{
// 			if (g_ms.prompt_line)
// 				free(g_ms.prompt_line);
// 			continue ;
// 		}
// }

void	repl_minshell(void)
{
	while (TRUE)
	{
		g_ms.prompt_line = create_prompt();
		create_tokens();
		expander();
		if (parser() == 1)
		{
			ft_lstclear(&g_ms.env, free);
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
	(void)argv;
	check_arguments(argc);
	init_minishell(envp);
	handle_signal();
	repl_minshell();
	return (EXIT_SUCCESS);
}

void	print_tokens(void)
{
	t_list		*node;
	t_tokens	*tklist;

	node = g_ms.tks;
	if (!g_ms.tks)
		return ;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		printf("tokens = %s\n", tklist->token);
		printf("id     = %d\n", tklist->id_token);
		node = node->next;
	}
}
