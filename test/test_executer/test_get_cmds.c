#include "../h_test.h"



void test_create_cmds(char *prompt, char *expected[], int len)
{
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	g_ms.prompt_line = ft_strdup(prompt);
	create_tokens();
	expander();
	parser();
	join_tokens(&g_ms.tks);
	reidentify_some_tokens(g_ms.tks);
	init_cmd_data();
	i = 0;
	while (g_ms.cmd_data.node)
	{
		get_cmds();
		TEST_ASSERT_EQUAL_STRING_ARRAY(expected[i], g_ms.cmd_data.argv, len);
		free_commands();
	}
	
	free(g_ms.prompt_line);
}

typedef struct s_test_cmds
{
	char array[2][2];

} t_cmds;

void	test_valid_create_cmds(void)
{
	t_cmds array =  {{"ls", "-l"}, {"wc", "-c"}};

	char *str;
	// char *array[2];


	str = "ls -l | wc -c";
	test_create_cmds(str, array, 2);
	free_ms();


}
