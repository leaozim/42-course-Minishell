#include "../h_test.h"

void	check_is_invalid_consecutive_metachar(void)
{
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|","|", PIPE, PIPE));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|", "<", PIPE, RDRCT_IN));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|",">", PIPE, RDRCT_OU));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|", ">>", PIPE, APPEND));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|", "<<", PIPE, HEREDOC));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<<", "<<", HEREDOC, HEREDOC));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<<", ">>", HEREDOC, APPEND));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<<", ">", HEREDOC, RDRCT_OU));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<<", "<", HEREDOC, RDRCT_IN));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<", "<", RDRCT_IN, RDRCT_IN));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("<", ">", RDRCT_IN, RDRCT_OU));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars(">", ">>", RDRCT_IN, APPEND));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars(">>", ">>", APPEND, APPEND));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars(">>", ">", APPEND, RDRCT_IN));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars(">>", ">", APPEND, RDRCT_OU));
	TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars(">", ">", RDRCT_OU, RDRCT_OU));
	// TEST_ASSERT_EQUAL_INT(1,  consecutive_metachars("|", "csmd", PIPE, COMMAND));
}

void	check_is_valid_consecutive_metachar(void)
{
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("cmd", "|", COMMAND, PIPE));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("cmd", "<<", COMMAND, HEREDOC));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("<<", "cmd", HEREDOC, COMMAND));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("cmd", ">", COMMAND, RDRCT_OU));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars(">", "cmd", RDRCT_OU, COMMAND));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("cmd", "<", COMMAND, RDRCT_IN));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("<", "cmd", RDRCT_IN, COMMAND));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars("cmd", ">>", COMMAND, APPEND));
	TEST_ASSERT_EQUAL_INT(0,  consecutive_metachars(">>", "cmd", APPEND, COMMAND));
}

void	test_error_syntax_consecutive_metachacacter(void)
{
	RUN_TEST(check_is_invalid_consecutive_metachar);
	RUN_TEST(check_is_valid_consecutive_metachar);
}
