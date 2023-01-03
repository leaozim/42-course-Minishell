#include "../h_test.h"

void test_join_token(char *prompt, char **expected)
{
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	ms.prompt_line = ft_strdup(prompt);
	create_tokens();
	parser();
	node = ms.tks;
	i = 0;
	while (node)

	{
		tklist = (t_tokens *)node->content;
		TEST_ASSERT_EQUAL_STRING(expected[i], tklist->token);
		node = node->next;
		i++;
		printf("%d\n", i);
	}
	free(ms.prompt_line);
}

// múltiplos conjuntos de aspas
// //"ola""tudo""bem"
// //"ola""tudo""bem""com"
// //"ola""tudo""bem""com""voce"
// //"ola""tudo""bem""com""voce""?"


// conjuntos separados
// //"ola" "tudo" "bem"
// //"ola" "tudo" "com" "voce"
// //"ola" "tudo" "com" "voce" "?"


// conjunto de aspas (2) entre tokens normais
// //oi "ola"tudo bem
// //oi ola"tudo" bem
// //oi "ola""tudo" bem

// //"oi" ola"tudo" "bem"
// //"oi" "ola"tudo "bem"
// //"oi" "ola""tudo" "bem"

// //oi "ola""tudo" "bem"
// //"oi" "ola""tudo" bem
// //oi ola"tudo" "bem"
// //oi "ola"tudo "bem"
// //"oi" "ola"tudo bem
// //"oi" ola"tudo" bem


// conjunto de aspas (3) entre tokens normais
// //oi "ola""tudo""bem" com
// //oi ola"tudo"bem com
// //oi "ola"tudo"bem" com

// //"oi" "ola""tudo""bem" "com"
// //"oi" ola"tudo"bem "com"
// //"oi" "ola"tudo"bem" "com"

// //oi "ola""tudo""bem" "com"
// //oi ola"tudo"bem "com"
// //oi "ola"tudo"bem" "com"

// //"oi" "ola""tudo""bem" com
// //"oi" ola"tudo"bem com
// //"oi" "ola"tudo"bem" com

void	test_valid_join_token(void)
{
	//                  tokens normais                    //
	test_join_token("oi ola", (char *[]){"oi", "ola", NULL});
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

	test_join_token("\"oi\"\"ola\"", (char *[]){"\"oi\"\"ola\"", NULL});
	free_ms();

	// test_join_token("\"oi\" \"tudo\"", (char *[]){"\"oi\"", "\"tudo\"", NULL});
	// free_ms();

	test_join_token("\"oi\"ola", (char *[]){"\"oi\"ola", NULL});
	free_ms();

	test_join_token("oi\"ola\"", (char *[]){"oi\"ola\"", NULL});
	free_ms();
	
	test_join_token("\"oi\" ola", (char *[]){"\"oi\"", "ola", NULL});
	free_ms();

	test_join_token("oi \"ola\"", (char *[]){"oi","\"ola\"", NULL});
	free_ms();


	
	//                    conjunto multiplos de aspas                     //
	
	test_join_token("\"ola\"\"tudo\"\"bem\"", (char *[]){"\"ola\"\"tudo\"\"bem\"", NULL});
	free_ms(); 

	// test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"", (char *[]){"\"ola\"\"tudo\"\"bem\"\"com\"", NULL});
	// free_ms();

	// test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"", (char *[]){"\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"", NULL});
	// free_ms();

	// test_join_token("\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"\"?\"", (char *[]){"\"ola\"\"tudo\"\"bem\"\"com\"\"voce\"\"?\"", NULL});
	// free_ms();


	//                    conjunto separados                    //

	//esses casos de erro o test nao pega:
	// test_join_token("\"ola\" \"tudo\" \"bem\"", (char *[]){"\"ola\"", "\"tudo\"", "\"bem\"", NULL});
	// free_ms();

	// test_join_token("\"ola\" \"tudo\" \"bem\" \"com\"", (char *[]){"\"ola\"", "\"tudo\"", "\"bem\"", "\"com\"", NULL});
	// free_ms();

	// 	test_join_token("\"ola\" \"tudo\" \"bem\" \"com\" \"?\"", (char *[]){"\"ola\"", "\"tudo\"", "\"bem\"", "\"com\"", "\"?\"", NULL});
	// free_ms();


	//                    conjunto de aspas (2) entre tokens normais                    //

	// test_join_token("oi \"ola\"tudo bem", (char *[]){"oi", "\"ola\"tudo", "bem", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\" bem", (char *[]){"oi", "ola\"tudo\"", "bem", NULL});
	// free_ms();

	// test_join_token("oi \"ola\"\"tudo\" bem", (char *[]){"oi", "\"ola\"\"tudo\"", "bem", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"\"tudo\" "\bem\"", (char *[]){"\"oi\"", "\"ola\"\"tudo\"", ""\bem\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" ola\"tudo\" "\bem\"", (char *[]){"\"oi\"", "ola\"tudo\"", ""\bem\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"\"tudo\" "\bem\"", (char *[]){"\"oi\"", "\"ola\"\"tudo\"", ""\bem\"", NULL});
	// free_ms();

	// test_join_token("oi \"ola\"\"tudo\" \"bem\"", (char *[]){"oi", "\"ola\"\"tudo\"", "\"bem\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"\"tudo\" bem", (char *[]){"\"oi\"", "\"ola\"\"tudo\"", "bem", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\" \"bem\"", (char *[]){"oi", "ola\"tudo\"", "\"bem\"", NULL});
	// free_ms();

	// test_join_token("oi \"ola\"tudo \"bem\"", (char *[]){"\"oi\"", "\"ola\"tudo", "\"bem\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"tudo bem", (char *[]){"\"oi\"", "\"ola\"tudo", "bem", NULL});
	// free_ms();

	// test_join_token("\"oi\" ola\"tudo\" bem", (char *[]){"\"oi\"", "ola\"tudo\"", "bem", NULL});
	// free_ms();

	//                    conjunto de aspas (3) entre tokens normais                    //

	// test_join_token("oi \"ola\"\"tudo\"\"bem\" com", (char *[]){"oi", "\"ola\"\"tudo\"\"bem\"", "com", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\"\"bem\" com", (char *[]){"oi", "ola\"tudo\"\"bem\"", "com", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\"bem com", (char *[]){"oi", "ola\"tudo\"bem", "com", NULL});
	// free_ms();

	// test_join_token("oi \"ola\"tudo\"bem\" com", (char *[]){"oi", "\"ola\"tudo\"bem\"", "com", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"\"tudo\"\"bem\" \"com\"", (char *[]){"\"oi\"", "\"ola\"\"tudo\"\"bem\"", "\"com\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" ola\"tudo\"\"bem\" \"com\"", (char *[]){"\"oi\"", "\"ola\"tudo\"\"bem\"", "\"com\"", NULL});
	// free_ms();

	// test_join_token("\"oi\" \"ola\"tudo\"bem\" \"com\"", (char *[]){"\"oi\"", "\"ola\"tudo\"bem\"", "\"com\"", NULL});
	// free_ms();

	// 	test_join_token("\"oi\" \"ola\"tudo\"bem\" com", (char *[]){"\"oi\"", "\"ola\"tudo\"bem\"", "com", NULL});
	// 	free_ms();

	// 	test_join_token("\"oi\" ola\"tudo\"\"bem\" com", (char *[]){"\"oi\"", "\"ola\"tudo\"\"bem\"", "com", NULL});
	// 	free_ms();

	// 	test_join_token("\"oi\" \"ola\"tudo\"bem\" com", (char *[]){"\"oi\"", "\"ola\"tudo\"bem\"", "com", NULL});
	// 	free_ms();

	// test_join_token("oi \"ola\"\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "\"ola\"\"tudo\"\"bem\"", "\"com\"", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\"\"bem\" \"com\"", (char *[]){"oi", "ola\"tudo\"\"bem\"", "\"com\"", NULL});
	// free_ms();

	// test_join_token("oi ola\"tudo\"bem \"com\"", (char *[]){"oi", "ola\"tudo\"bem", "\"com\"", NULL});
	// free_ms();
}