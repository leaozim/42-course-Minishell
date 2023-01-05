#include "../include/minishell.h"

// void is_error(char *prompt_line)
// {
// 	if (is_erro_sintaxy_quotes(ms.prompt_line))
// 		{
// 			if (ms.prompt_line)
// 				free(ms.prompt_line);
// 			continue ;
// 		}
// }

void	repl_minshell(void)
{
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		create_tokens();
		parser();
		printf(CYAN"\nANTES\n"RESET);
		print_tokens();
		expander();
		join_tokens(&ms.tks);
		reidentify_some_tokens(ms.tks);
		is_builtins();
		printf(CYAN"DEPOIS\n"RESET);
		print_tokens();
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

	if (!ms.tks)
		return ;
	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		printf("tokens = %s\n", tklist->token);
		printf("id     = %d\n", tklist->id_token);
		node = node->next;
	}
}
