# include "h_test.h"
#include "unity/unity.h"

void	check_case_double_quotes()
{
	char	*str;

	str = expander("$HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), str);

	str = case_double_quotes("\"oi $HOME $*$ $ tudo $$ $OLDPWD $? ?$\"");
	TEST_ASSERT_EQUAL_STRING("oi /home/etomiyos $*$ $ tudo $$ /home/etomiyos/42projetos $? ?$", str);

	str = case_double_quotes("$");
	TEST_ASSERT_EQUAL_STRING("$", str);

	str = case_double_quotes("$!");
	TEST_ASSERT_EQUAL_STRING("$", str);

	str = case_double_quotes("$ $");
	TEST_ASSERT_EQUAL_STRING("$ $", str);

	// str = case_double_quotes("     ");
	// TEST_ASSERT_EQUAL_STRING("     ", str);

	// str = case_double_quotes(" ");
	// TEST_ASSERT_EQUAL_STRING(" ", str);

	str = case_double_quotes("");
	TEST_ASSERT_EQUAL_STRING("", str);

	// str = case_double_quotes(" $");
	// TEST_ASSERT_EQUAL_STRING(" $", str);

	// str = case_double_quotes("$SHELL$SHELL$SHELL");
	// TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash/bin/bash", str);

	str = case_double_quotes("$#$#");
	TEST_ASSERT_EQUAL_STRING("$#$", str);

	str = case_double_quotes("$$$$");
	TEST_ASSERT_EQUAL_STRING("$$$$", str);

	str = case_double_quotes("$$");
	TEST_ASSERT_EQUAL_STRING("$$", str);
}