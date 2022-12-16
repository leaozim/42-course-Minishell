// #include "../h_test.h"

// void create_valid_metachacacter(char *prompt)
// {
// 	t_list		*no;

// 	ms.prompt_line = ft_strdup(prompt);
// 	is_erro_sintaxy_quotes(ms.prompt_line);
// 	create_tokens();
// 	error_syntaxy_metachars(ms.tks, ms.len_tokens);
// 	no = ms.tks;
// 	while (no)
// 	{
// 		TEST_ASSERT_EQUAL_INT(0, error_syntaxy_metachars(ms.tks, ms.len_tokens));
// 		no = no->next;
// 	}
// 	free(ms.prompt_line);
// }

// void create_invalid_metachacacter(char *prompt)
// {
// 	t_list		*no;

// 	ms.prompt_line = ft_strdup(prompt);
// 	is_erro_sintaxy_quotes(ms.prompt_line);
// 	create_tokens();
// 	error_syntaxy_metachars(ms.tks, ms.len_tokens);
// 	no = ms.tks;
// 	while (no)
// 	{
// 		TEST_ASSERT_EQUAL_INT(1, error_syntaxy_metachars(ms.tks, ms.len_tokens));
// 		no = no->next;
// 	}
// 	free(ms.prompt_line);
// }


// void	test_is_error_syntax_metachacacter(void)
// {

// 	t_minishell ms;
// 	create_valid_metachacacter(creat_minishell(&ms), "ls -la");
// 	free_ms(&ms);

// 	t_minishell ms2;
// 	create_invalid_metachacacter(creat_minishell(&ms2), "ls || oi");
// 	free_ms(&ms2);

// 	t_minishell ms3;
// 	create_invalid_metachacacter(creat_minishell(&ms3), "ls >> >> oi");
// 	free_ms(&ms3);

// 	t_minishell ms4;
// 	create_invalid_metachacacter(creat_minishell(&ms4), "ls << << oi");
// 	free_ms(&ms4);

// 	t_minishell ms5;
// 	create_invalid_metachacacter(creat_minishell(&ms5), "ls < < oi");
// 	free_ms(&ms5);

// 	t_minishell ms6;
// 	create_invalid_metachacacter(creat_minishell(&ms6), "ls > > oi");
// 	free_ms(&ms6);

// 	t_minishell ms7;
// 	create_invalid_metachacacter(creat_minishell(&ms7), "ls > < oi");
// 	free_ms(&ms7);

// 	t_minishell ms8;
// 	create_invalid_metachacacter(creat_minishell(&ms8), "ls << >> oi");
// 	free_ms(&ms8);

// 	t_minishell ms9;
// 	create_invalid_metachacacter(creat_minishell(&ms9), "ls < > oi");
// 	free_ms(&ms9);

// 	t_minishell ms10;
// 	create_invalid_metachacacter(creat_minishell(&ms10), "ls | > oi");
// 	free_ms(&ms10);

// 	t_minishell ms11;
// 	create_invalid_metachacacter(creat_minishell(&ms11), "ls << | oi");
// 	free_ms(&ms11);

// 	t_minishell ms12;
// 	create_invalid_metachacacter(creat_minishell(&ms12), "ls | << oi");
// 	free_ms(&ms12);

// 	t_minishell ms13;
// 	create_invalid_metachacacter(creat_minishell(&ms13), "ls | < oi");
// 	free_ms(&ms13);

// 	t_minishell ms14;
// 	create_invalid_metachacacter(creat_minishell(&ms14), ">");
// 	free_ms(&ms14);

// 	t_minishell ms15;
// 	create_invalid_metachacacter(creat_minishell(&ms15), ">");
// 	free_ms(&ms15);

// 	t_minishell ms16;
// 	create_invalid_metachacacter(creat_minishell(&ms16), ">>");
// 	free_ms(&ms16);

	
// 	t_minishell ms17;
// 	create_invalid_metachacacter(creat_minishell(&ms17), "<");
// 	free_ms(&ms17);

// 	t_minishell ms18;
// 	create_invalid_metachacacter(creat_minishell(&ms18), "<<");
// 	free_ms(&ms18);

// 	t_minishell ms19;
// 	create_invalid_metachacacter(creat_minishell(&ms19), "|");
// 	free_ms(&ms19);
// }
