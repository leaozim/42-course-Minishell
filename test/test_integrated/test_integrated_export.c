// #include "../h_test.h"

// void	free_ms_export(void)
// {
// 	ft_lstclear(&g_ms.tks, destroy_t_tokens);
// 	free(g_ms.tab_tokens);
// 	free(g_ms.tab_id);
// 	ft_lstclear(&g_ms.env, free);
// }

// void create_export_valid(char *prompt, char *expected)
// {
// 	t_list			*node;

// 	g_ms.prompt_line = ft_strdup(prompt);
// 	create_tokens();
// 	parser();
// 	expander();
// 	is_builtins();
// 	node = g_ms.env;
// 	node = ft_lstlast(node);
// 	TEST_ASSERT_EQUAL_STRING(expected, node->content);
// 	free(g_ms.prompt_line);
// }

// void create_export_invalid(char *prompt)
// {
// 	g_ms.prompt_line = ft_strdup(prompt);
// 	create_tokens();
// 	parser();
// 	expander();
// 	is_builtins();
// 	TEST_ASSERT_EQUAL_INT(1, g_ms.exit_status);
// 	free(g_ms.prompt_line);
// }

// void    check_export(void)
// {
	// create_export_valid("export OLA=", "OLA=");
	// free_ms_export();

	// create_export_valid("export OLA====PESSOAL", "OLA====PESSOAL");
	// free_ms_export();

	// create_export_valid("export OLA", "OLA");
	// free_ms_export();

	// create_export_valid("export \"OLA\"", "OLA");
	// free_ms_export();

	// create_export_valid("export OLA=PESSOAL", "OLA=PESSOAL");
	// free_ms_export();

	// create_export_invalid("export OLA%");
	// free_ms_export();

	// create_export_valid("export OLA=%PESSOAL", "OLA=%PESSOAL");
	// free_ms_export();

	// create_export_invalid("export %=PESSOAL");
	// free_ms_export();

	// create_export_invalid("export 2=PESSOAL");
	// free_ms_export();

	// create_export_invalid("export %A=PESSOAL");
	// free_ms_export();

	// create_export_valid("export _2=PESSOAL", "_2=PESSOAL");
	// free_ms_export();

	// create_export_invalid("export 2_=PESSOAL");
	// free_ms_export();

	// create_export_invalid("export =PESSOAL");
	// free_ms_export();

	// create_export_valid("export OLA=2PESSOAL", "OLA=2PESSOAL");
	// free_ms_export();

	// create_export_valid("export OLA=2", "OLA=2");
	// free_ms_export();

	// create_export_valid("export OLA=2", "OLA=2");
	// free_ms_export();

	// create_export_valid("export OLA=\"ola\"", "OLA=\"ola\"");
	// free_ms_export();

	// create_export_valid("export OLA=\"|\"", "OLA=\"|\"");
	// free_ms_export();

	// create_export_valid("export OLA=\"<\"", "OLA=\"<\"");
	// free_ms_export();

	// create_export_valid("export OLA=\">\"", "OLA=\">\"");
	// free_ms_export();

	// create_export_valid("export OLA=\">>\"", "OLA=\">>\"");
	// free_ms_export();

	// create_export_valid("export OLA=\"<<\"", "OLA=\"<<\"");
	// free_ms_export();

	// create_export_valid("export OLA=\"%PESSOAL\"", "OLA=\"%PESSOAL\"");
	// free_ms_export();

	// create_export_valid("export OLA=\'%PESSOAL\'", "OLA=\'%PESSOAL\'");
	// free_ms_export();

	// create_export_valid("export OLA=\"PESSOAL\"", "OLA=\"PESSOAL\"");
	// free_ms_export();
// }