#include "../h_test.h"

void create_valid_metachacacter(char *prompt)
{
	t_list		*node;

	g_ms.prompt_line = ft_strdup(prompt);
	is_syntax_quote_error(g_ms.prompt_line);
	create_tokens();
	// error_syntaxy_metachars(g_ms.tks, g_ms.len_tokens);
	node = g_ms.tks;
	while (node)
	{
		TEST_ASSERT_EQUAL_INT(0, error_syntaxy_metachars(g_ms.tks, g_ms.len_tokens));
		node = node->next;
	}
	free(g_ms.prompt_line);
}

void create_invalid_metachacacter(char *prompt)
{
	t_list		*node;

	g_ms.prompt_line = ft_strdup(prompt);
	is_syntax_quote_error(g_ms.prompt_line);
	create_tokens();
	// error_syntaxy_metachars(g_ms.tks, g_ms.len_tokens);
	node = g_ms.tks;
	while (node)
	{
		TEST_ASSERT_EQUAL_INT(1, error_syntaxy_metachars(g_ms.tks, g_ms.len_tokens));
		node = node->next;
	}
	free(g_ms.prompt_line);
}


void	test_is_error_syntax_metachacacter(void)
{
	create_valid_metachacacter("s -la");
	free_ms();

	create_valid_metachacacter("s | -la");
	free_ms();

	create_valid_metachacacter("s > -la");
	free_ms();

	create_valid_metachacacter("s <-la");
	free_ms();

	create_valid_metachacacter("s << -la");
	free_ms();

	create_valid_metachacacter("s >> -la");
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
	
	create_invalid_metachacacter("OLA=|");
	free_ms();

	create_invalid_metachacacter("OLA=<");
	free_ms();

	create_invalid_metachacacter("OLA=>");
	free_ms();

	create_invalid_metachacacter("OLA=<<");
	free_ms();

	create_invalid_metachacacter("OLA=>>");
	free_ms();
}
