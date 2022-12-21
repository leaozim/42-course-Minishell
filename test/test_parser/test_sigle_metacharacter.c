#include "../h_test.h"

void	check_is_invalid_single_metacharacte(void)
{
	TEST_ASSERT_EQUAL_INT(1,  is_single_metachar("<", RDRCT_IN, 1));
	TEST_ASSERT_EQUAL_INT(1,  is_single_metachar(">", RDRCT_OU, 1));
	TEST_ASSERT_EQUAL_INT(1,  is_single_metachar("<<", HEREDOC, 1));
	TEST_ASSERT_EQUAL_INT(1,  is_single_metachar(">>", APPEND, 1));
	TEST_ASSERT_EQUAL_INT(1,  is_single_metachar("|", PIPE, 1));
}

void	check_is_valid_return_single_metacharacte(void)
{
	TEST_ASSERT_EQUAL_INT(0,  is_single_metachar("<", RDRCT_IN, 10));
	TEST_ASSERT_EQUAL_INT(0,  is_single_metachar(">", RDRCT_OU, 12));
	TEST_ASSERT_EQUAL_INT(0,  is_single_metachar("<<",HEREDOC, 2));
	TEST_ASSERT_EQUAL_INT(0,  is_single_metachar(">>", APPEND, 5));
	TEST_ASSERT_EQUAL_INT(0,  is_single_metachar("|", PIPE, 3));
}

void	test_error_syntax_single_metachacacter(void)
{
	RUN_TEST(check_is_valid_return_single_metacharacte);
}
