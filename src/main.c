#include "../include/minishell.h"
// #include <minishell.h>

void	repl_minshell(void)
{
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens();
		// print_tokens();
		parser();
		printf(CYAN"\nEXPANDER\n"RESET);
		expander();
		print_tokens();
		destroy_minishell();
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
	t_list			*no;
	t_lst_tokens	*temp;

	no = ms.tks;
	while (no)
	{
		temp = (t_lst_tokens *)no->content;
		printf("tokens = %s\n", temp->token);
		printf("id     = %d\n", temp->id_token);
		no = no->next;
	}
}
