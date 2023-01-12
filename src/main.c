#include "../include/minishell.h"

void	repl_minshell(void)
{
	while (TRUE)
	{
		g_ms.prompt_line = create_prompt();
		create_tokens();
		expander();
		parser();
		join_tokens(&g_ms.tks);
		printf(CYAN"\nANTES\n"RESET);
		print_tokens();
		reidentify_some_tokens(g_ms.tks);
		is_builtins();
		printf(CYAN"DEPOIS\n"RESET);
		print_tokens();
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

	if (!g_ms.tks)
		return ;
	node = g_ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		printf("tokens = %s\n", tklist->token);
		printf("id     = %d\n", tklist->id_token);
		node = node->next;
	}
}
