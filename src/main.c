#include "../include/minishell.h"

int	main(int argc, char **argv)
{
	t_minishell	ms;

	(void)argv;
	check_arguments(argc);
	init_minishell(&ms);
	while (TRUE)
	{
		ms.prompt_line = create_prompt();

		printf(CYAN"\nTOKENS\n"RESET);

		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens(&ms);
		print_tokens(&ms);

		//EXPANDER
		printf(CYAN"\nEXPANDER\n"RESET);
		char *str = expander("$DDOIDERA");
		if (str != NULL)
			printf("%s\n", str);

		free(ms.prompt_line);
		//
	}
	return (EXIT_SUCCESS);
}

void	print_tokens(t_minishell *ms)
{
	t_list		*no;
	t_tokens	*temp;

	no = ms->tks;
	while (no)
	{
		temp = (t_tokens *)no->content;
		printf("tokens = %s\n", temp->tokens);
		printf("id     = %d\n", temp->id_tks);
		no = no->next;
	}
}
