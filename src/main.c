#include "../include/minishell.h"

void	repl_minshell(void)
{
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens();
		parser();
		expander();
		// echo();
		print_tokens();
		builtin_env();
		builtin_export("OLAGALERA");
		is_builtins();
		destroy_minishell();
	}
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

	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		printf("tokens = %s\n", tklist->token);
		printf("id     = %d\n", tklist->id_token);
		node = node->next;
	}
}
