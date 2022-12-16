#include "../h_test.h"

void free_ms(void)
{
	free_ptrs(ms.tab_tokens);
	ft_lstclear(&ms.tks, free);
	free(ms.tab_id);
}

void create_repl(char *prompt, int *array_int)
{
	t_list		*no;
	t_tokens	*tks;

	ms.prompt_line = ft_strdup(prompt);
	is_erro_sintaxy_quotes(ms.prompt_line);
	create_tokens();
	parser();
	no = ms.tks;
	while (no)
	{
		tks = (t_tokens *)no->content;
		TEST_ASSERT_EQUAL_INT(*array_int, tks->id_tks);
		array_int++;
		no = no->next;
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

	int expected5[3] = {COMMAND, RDRCT_IN, FILE_IN};
	create_repl("ls < oi", expected5);
	free_ms();

	int expected6[3] = {COMMAND, RDRCT_OU, FILE_OUT};
	create_repl( "ls > oi", expected6);
	free_ms();

	int expected7[4] = {COMMAND, RDRCT_OU, RDRCT_OU, COMMAND};
	create_repl("ls > > oi", expected7);
	free_ms();

	int expected4[3] = {COMMAND, HEREDOC};
	create_repl("ls <<", expected4);
	free_ms();
}
