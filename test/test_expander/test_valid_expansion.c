#include "../h_test.h"

void check_valid_expansion(void)
{
	char *str;

	str = expander("$HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), str);

	str = expander("$IS_NOT_HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("IS_NOT_HOME"), str);

	//export DOIDERA="oi"
	str = expander("$DOIDERA");
	TEST_ASSERT_EQUAL_STRING(getenv("DOIDERA"), str);
}