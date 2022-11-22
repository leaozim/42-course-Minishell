# include "h_test.h"

void	checar_se_as_aspas_sao_validas(void)
{
	char *str;
	
	str = ft_strdup("echo \"oi\"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);
	
	str = ft_strdup("echo \"oi \' \"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);

	str = ft_strdup("echo \"oi \' dsdf\' \"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);

	str = ft_strdup("echo oi\"oi\" \"$HOME\" \'$HOME\' $HOME \"\'$HOME\'\"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);

	str = ft_strdup("echo -n oi\"oi\" \"$HOME\" \'$HOME\' $HOME \"\'$HOME\'\"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);

	str = ft_strdup("echo oi\"oi\"$HOME\"$HOME\"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);

	str = ft_strdup("cat <Makefile>out|tr \" \" \"x\"");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);
	
	str = ft_strdup("cat <Makefile>out|tr \" \" \"x\">out");
	TEST_ASSERT_EQUAL(TRUE,  is_valid_quoting(&str));
	free(str);


}

void	checar_se_as_aspas_sao_invalidas(void)
{
	TEST_ASSERT_EQUAL(FALSE,  is_valid_quoting((char *[]){"echo \"oi \" \"", NULL}));
	TEST_ASSERT_EQUAL(FALSE,  is_valid_quoting((char *[]){"echo \"oi \' \'", NULL}));
	TEST_ASSERT_EQUAL(FALSE,  is_valid_quoting((char *[]){"echo \'oi \' \"", NULL}));
	TEST_ASSERT_EQUAL(FALSE,  is_valid_quoting((char *[]){"echo \'oi \' \'", NULL}));
	TEST_ASSERT_EQUAL(FALSE,  is_valid_quoting((char *[]){"echo oi\"oi \'oi \' \" oi \"oi<oi\"OI\'oi", NULL}));
}

void	test_check_valid_quoting(void)
{
	RUN_TEST(checar_se_as_aspas_sao_validas);
	RUN_TEST(checar_se_as_aspas_sao_invalidas);
}
