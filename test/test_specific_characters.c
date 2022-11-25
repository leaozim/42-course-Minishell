# include "h_test.h"

void	check_token_count_squote()
{
	TEST_ASSERT_EQUAL_INT(11, 11);
	TEST_ASSERT_EQUAL_INT(11, 11);
}

void	check_token_count_dquotes()
{
	TEST_ASSERT_EQUAL_INT(11, 11);
}

void	check_token_count_mixed_quotes()
{
	TEST_ASSERT_EQUAL_INT(11, 11);
}

void	check_token_count_parallel_quotes()
{
	TEST_ASSERT_EQUAL_INT(8, 8);
	TEST_ASSERT_EQUAL_INT(8, 8);
}

void	check_token_count_detached_quote()
{
	TEST_ASSERT_EQUAL_INT(1, 1);
	TEST_ASSERT_EQUAL_INT(1, 1);
	TEST_ASSERT_EQUAL_INT(5, 5);
}

void	check_token_count_pipe()
{
	TEST_ASSERT_EQUAL_INT(4, 4);
	TEST_ASSERT_EQUAL_INT(4, 4);
}

void	check_token_count_greaterthan()
{
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(3, 3);
}

void	check_token_count_lessthan()
{
	TEST_ASSERT_EQUAL_INT(4, 4);
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(4, 4);
}

void	check_token_count_double_greaterthan()
{
	TEST_ASSERT_EQUAL_INT(4, 4);
}

void	check_token_count_double_lessthan()
{
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(3, 3);
}

void	check_token_count_general()
{
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(9, 9);
	TEST_ASSERT_EQUAL_INT(13, 13);
}

void	check_token_count_quotes(void)
{
	check_token_count_squote();
	check_token_count_dquotes();
	check_token_count_mixed_quotes();
	check_token_count_parallel_quotes();
	check_token_count_detached_quote();
}

void	check_token_count_redirection(void)
{
	check_token_count_pipe();
	check_token_count_greaterthan();
	check_token_count_lessthan();
	check_token_count_double_greaterthan();
	check_token_count_double_lessthan();
}

void	check_token_qtt(void)
{
	RUN_TEST(check_token_count);
}

void	check_token_count(void)
{
	check_token_count_general();
	check_token_count_quotes();
	check_token_count_redirection();
}