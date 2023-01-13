#include "../h_test.h"

void test_join_token(char *prompt, char **expected)
{
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	g_ms.prompt_line = ft_strdup(prompt);
	create_tokens();
	parser();
	expander();
	join_tokens(&g_ms.tks);
	reidentify_some_tokens(g_ms.tks);
	node = g_ms.tks;
	i = 0;
	while (node)

	{
		tklist = (t_tokens *)node->content;
		TEST_ASSERT_EQUAL_STRING(expected[i], tklist->token);
		node = node->next;
		i++;
	}
	free(g_ms.prompt_line);
}

void	test_valid_join_token(void)
{
	//                  tokens normais                    //

	test_join_token("oi ola", (char *[]){"oi", "ola", NULL});
	free_ms();

	test_join_token("echo ola\"\"ola", (char *[]){"oi", "olaola", NULL});
	free_ms();

	test_join_token("oi ola tudo", (char *[]){"oi", "ola", "tudo", NULL});
	free_ms();

	test_join_token("oi < tudo", (char *[]){"oi", "<", "tudo", NULL});
	free_ms();

	test_join_token("oi<tudo", (char *[]){"oi", "<", "tudo", NULL});
	free_ms();
	
	//                    conjunto único de aspas                     //

	test_join_token("oi", (char *[]){"oi", NULL});
	free_ms();

	test_join_token("\"oi\"\"ola\"", (char *[]){"oiola", NULL});
	free_ms();

	test_join_token("\"oi\" \"tudo\"", (char *[]){"oi", "tudo", NULL});
	free_ms();

	test_join_token("\"oi\"ola", (char *[]){"oiola", NULL});
	free_ms();

	test_join_token("oi\"ola\"", (char *[]){"oiola", NULL});
	free_ms();
	
	test_join_token("\"oi\" ola", (char *[]){"oi", "ola", NULL});
	free_ms();

	test_join_token("oi \"ola\"", (char *[]){"oi","ola", NULL});
	free_ms();

	//                    conjunto multiplos de aspas                     //
	
	test_join_token("\"ola\"\"tudo\"\"bem\"", (char *[]){"olatudobem", NULL});
	free_ms(); 

	test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"", (char *[]){"olatudobemcom", NULL});
	free_ms();

	test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"", (char *[]){"olatudobemcomvoce", NULL});
	free_ms();

	test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"\"?\"", (char *[]){"olatudobemcomvoce?", NULL});
	free_ms();

	//                    conjunto separados                    //

	test_join_token("\"ola\" \"tudo\" \"bem\"", (char *[]){"ola", "tudo", "bem", NULL});
	free_ms();

	test_join_token("\"ola\" \"tudo\" \"bem\" \"com\"", (char *[]){"ola", "tudo", "bem", "com", NULL});
	free_ms();

	test_join_token("\"ola\" \"tudo\" \"bem\" \"com\" \"?\"", (char *[]){"ola", "tudo", "bem", "com", "?", NULL});
	free_ms();

	//                    conjunto de aspas (2) entre tokens normais                    //

	test_join_token("oi \"ola\"tudo bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("oi ola\"tudo\" bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("oi \"ola\"\"tudo\" bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"\"tudo\" \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" ola\"tudo\" \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"\"tudo\" \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("oi \"ola\"\"tudo\" \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"\"tudo\" bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("oi ola\"tudo\" \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("oi \"ola\"tudo \"bem\"", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"tudo bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	test_join_token("\"oi\" ola\"tudo\" bem", (char *[]){"oi", "olatudo", "bem", NULL});
	free_ms();

	//                    conjunto de aspas (3) entre tokens normais                    //

	test_join_token("oi \"ola\"\"tudo\"\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi ola\"tudo\"\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi ola\"tudo\"bem com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi \"ola\"tudo\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi \"ola\"\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("\"oi\" ola\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"tudo\"bem\" \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"tudo\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("\"oi\" ola\"tudo\"\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("\"oi\" \"ola\"tudo\"bem\" com", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi \"ola\"\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi ola\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	free_ms();

	test_join_token("oi ola\"\"tudo\"\"bem \"com\"", (char *[]){"oi", "\"olatudobem\"", "com", NULL});
	free_ms();

		// test_join_token("s \"ola\"\"tudo\"\"bem \"com\"", (char *[]){"oi", "olatudobem", "com", NULL});
	// free_ms();
}