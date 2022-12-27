// # include "../h_test.h"

// void	test_builtin_echo(char *prompt, char **expected)
// {
// 	t_list		*node;
// 	t_tokens	*tklist;

// 	ms.prompt_line = ft_strdup(prompt);
// 	is_erro_sintaxy_quotes(ms.prompt_line);
// 	create_tokens();
// 	parser();
// 	expander();
// 	echo();
// 	node = ms.tks;
// 	while (node)
// 	{
// 		tklist =  ms.tks->content;
// 		TEST_ASSERT_EQUAL_STRING(expected, tklist->token);
// 		node = node->next;
// 	}
// 	free(ms.prompt_line);
// }

// void	test_integrated_builtin_echo(void)
// {
	
// 	test_builtin_echo("echo -n \"oi\"", (char *[]){"\'echo\'", "\'oi\'", NULL});
// }