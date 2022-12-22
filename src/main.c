#include "../include/minishell.h"

void	repl_minshell(void)
{
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens();
		parser();
		printf(CYAN"\nEXPANDER\n"RESET);
		expander();
		print_tokens();
		destroy_minishell();
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	check_arguments(argc);
	init_minishell(envp);
	env();
	handle_signal();
	repl_minshell();
	return (EXIT_SUCCESS);
}

void	print_tokens(void)
{
	t_list		*no;
	t_tokens	*tklist;

	no = ms.tks;
	while (no)
	{
		tklist = (t_tokens *)no->content;
		printf("tokens = %s\n", tklist->token);
		printf("id     = %d\n", tklist->id_token);
		no = no->next;
	}
}
