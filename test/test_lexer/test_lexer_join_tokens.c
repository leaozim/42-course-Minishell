#include "../h_test.h"

void test_join_token(char *prompt, char **expected)
{
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	ms.prompt_line = ft_strdup(prompt);
	create_tokens();
	parser();
	// expander();
	node = ms.tks;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		TEST_ASSERT_EQUAL_STRING(expected[i], tklist->token);
		node = node->next;
		i++;
	}
	free(ms.prompt_line);
}


// tokens normais
// //oi
// //oi ola
// //oi ola tudo
// //oi < tudo
// //oi<tudo


// conjunto único de aspas
// //"oi"
// //"oi""ola"
// //"ola" "tudo"
// //"oi"ola
// //oi"ola"
// //"oi" ola
// //oi "ola"


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
	test_join_token("\"s\"\"-la\"", (char *[]){"\"s\"\"-la\"", NULL});
	free_ms();

	test_join_token("oi \"ola\"\"tudo\"\"bem\" com", (char *[]){"oi", "\"ola\"\"tudo\"\"bem\"", "com", NULL});
	free_ms();
}