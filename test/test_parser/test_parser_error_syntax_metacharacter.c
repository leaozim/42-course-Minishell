#include "../h_test.h"

void create_valid_metachacacter(char *prompt)
{
	t_list		*node;

	ms.prompt_line = ft_strdup(prompt);
	is_erro_sintaxy_quotes(ms.prompt_line);
	create_tokens();
	// error_syntaxy_metachars(ms.tks, ms.len_tokens);
	node = ms.tks;
	while (node)
	{
		TEST_ASSERT_EQUAL_INT(0, error_syntaxy_metachars(ms.tks, ms.len_tokens));
		node = node->next;
	}
	free(ms.prompt_line);
}

void create_invalid_metachacacter(char *prompt)
{
	t_list		*node;

	ms.prompt_line = ft_strdup(prompt);
	is_erro_sintaxy_quotes(ms.prompt_line);
	create_tokens();
	// error_syntaxy_metachars(ms.tks, ms.len_tokens);
	node = ms.tks;
	while (node)
	{
		TEST_ASSERT_EQUAL_INT(1, error_syntaxy_metachars(ms.tks, ms.len_tokens));
		node = node->next;
	}
	free(ms.prompt_line);
}


void	test_is_error_syntax_metachacacter(void)
{
	create_valid_metachacacter("s -la");
	free_ms();

	create_invalid_metachacacter("ls || oi");
	free_ms();

	create_invalid_metachacacter("ls >> >> oi");
	free_ms();

	create_invalid_metachacacter("ls << << oi");
	free_ms();

	create_invalid_metachacacter("ls < < oi");
	free_ms();

	create_invalid_metachacacter("ls > > oi");
	free_ms();

	create_invalid_metachacacter("ls > < oi");
	free_ms();

	create_invalid_metachacacter("ls << >> oi");
	free_ms();

	create_invalid_metachacacter("ls < > oi");
	free_ms();

	create_invalid_metachacacter("ls | > oi");
	free_ms();

	create_invalid_metachacacter("ls << | oi");
	free_ms();
	
	create_invalid_metachacacter("ls | << oi");
	free_ms();
	
	create_invalid_metachacacter("ls | < oi");
	free_ms();
	
	create_invalid_metachacacter(">");
	free_ms();
	
	create_invalid_metachacacter(">");
	free_ms();

	create_invalid_metachacacter(">>");
	free_ms();

	create_invalid_metachacacter("<");
	free_ms();

	create_invalid_metachacacter("<<");
	free_ms();
	
	create_invalid_metachacacter("|");
	free_ms();
}
