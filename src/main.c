#include "../include/minishell.h"

void	repl_minshell(void)
{
	while (TRUE)
	{
		ms.prompt_line = create_prompt();
		create_tokens();
		parser();
		expander();
		is_builtins();
		executer();
		// print_tokens();
		destroy_minishell();
	}
	ft_lstclear(&ms.env, free);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
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
