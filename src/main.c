#include "../include/minishell.h"
// #include <minishell.h>


void	repl_minshell(void)
{
	char		*str;

	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		printf(CYAN"\nTOKENS\n"RESET);
		is_erro_sintaxy_quotes(ms.prompt_line);
		create_tokens();
		print_tokens();
		parser();
		printf(CYAN"\nEXPANDER\n"RESET);
		str = ft_strdup("${SHELL  }");
		char *str1 = expander(str);
		printf("token expandido: |%s|\n", str1);
		free(str);
		free(str1);
		destroy_minishell();
	}
}

int	main(int argc, char **argv)
{
	// t_minishell	ms;

	(void)argv;
	check_arguments(argc);
	init_minishell();
	handle_signal();
	repl_minshell();
	return (EXIT_SUCCESS);
}

void	print_tokens(void)
{
	t_list		*no;
	t_tokens	*temp;

	no = ms.tks;
	while (no)
	{
		temp = (t_tokens *)no->content;
		printf("tokens = %s\n", temp->tokens);
		printf("id     = %d\n", temp->id_tks);
		no = no->next;
	}
}
