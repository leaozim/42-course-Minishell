#include "../h_test.h"

void	free_ms(void)
{
	ft_lstclear(&ms.tks, destroy_t_tokens);
	free(ms.tab_tokens);
	free(ms.tab_id);
	ft_lstclear(&ms.env, free);
}

void create_repl(char *prompt, int *array_int)
{
	t_list			*node;
	t_tokens		*tklist;

	ms.prompt_line = ft_strdup(prompt);
	create_tokens();
	parser();
	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		TEST_ASSERT_EQUAL_INT(*array_int, tklist->id_token);
		array_int++;
		node = node->next;
	}
	free(ms.prompt_line);
}

void check_repl(void)
{
	int expected[2] = {COMMAND, COMMAND};
	create_repl("ls -la", expected);
	free_ms();
	
	int expected2[3] = {COMMAND, PIPE, COMMAND};
	create_repl("ls | oi", expected2);
	free_ms();

	int expected3[3] = {COMMAND, APPEND, FILE_APPEND};
	create_repl("ls >> oi", expected3);
	free_ms();

	int expected4[3] = {COMMAND, HEREDOC};
	create_repl("ls <<", expected4);
	free_ms();

	int expected5[3] = {COMMAND, RDRCT_IN, FILE_IN};
	create_repl("ls < oi", expected5);
	free_ms();

	int expected6[3] = {COMMAND, RDRCT_OU, FILE_OUT};
	create_repl("ls > oi", expected6);
	free_ms();
}
