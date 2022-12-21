#include "../include/minishell.h"

void	repl_minshell(void)
{
	// char		*str;
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		// printf(CYAN"\nTOKENS\n"RESET);
		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens();
		parser();
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	check_arguments(argc);
	init_minishell();
	handle_signal();
	repl_minshell();
	return (EXIT_SUCCESS);
}

void	print_tokens(void)
{
	t_list		*node;
	t_tokens	*temp;

	node = ms.tks;
	while (node)
	{
		temp = (t_tokens *)node->content;
		printf("tokens = %s\n", temp->tokens);
		printf("id     = %d\n", temp->id_tks);
		node = node->next;
	}
}
