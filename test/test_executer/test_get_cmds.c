#include "../h_test.h"



// void test_create_cmds(char *prompt, char *expected[3][3], int len)
// {
// 	t_list		*node;
// 	t_tokens	*tklist;
// 	int			i;

// 	g_ms.prompt_line = ft_strdup(prompt);
// 	create_tokens();
// 	expander();
// 	parser();
// 	join_tokens(&g_ms.tks);
// 	reidentify_some_tokens(g_ms.tks);
// 	init_cmd_data();
// 	i = 0;
// 	int j = 0;
// 	// while (i < len)
// 	// {
// 	// 	get_cmds();
// 	// 	printf("argv %s\n", g_ms.cmd_data.argv[0]);
// 	// 	printf("arge %s\n", expected[i][0]);
// 	// 	TEST_ASSERT_EQUAL_STRING(expected[i][0], g_ms.cmd_data.argv[0]);
// 	// 	// free_commands();
// 	// 	i++;
// 	// 	j++;
// 	// }
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d\n", i);
// 		get_cmds();
// 		printf("argv %s\n", g_ms.cmd_data.argv[0]);
// 		printf("arge %s\n", expected[0][i]);
// 		TEST_ASSERT_EQUAL_STRING(expected[0][i], g_ms.cmd_data.argv[0]);
// 		free_commands();
// 		i++;
// 		j++;
// 	}
	
// 	free(g_ms.prompt_line);
// }

// void	test_valid_create_cmds(void)
// {
// 	char *array[3][3] = {{"ls", "-l"}, {"wc", "-c"}};
// 	char *str;

// 	str = "ls -l | wc -c";
// 	test_create_cmds(str, array, 2);
// 	free_ms();

// 	// char *array2[3][3] = {{"echo", "a"}, {"wc", "-c"}};
	
// 	// str = "echo a > txt | wc -c";
// 	// test_create_cmds(str, array2, 2);
// 	// free_ms();


// }
