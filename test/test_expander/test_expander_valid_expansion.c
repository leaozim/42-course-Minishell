#include "../h_test.h"

void check_valid_expansion(void)
{
	char *str;
	char *aux;

	str = expander("$HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), str);
	free(str);

	str = expander("$HOME$HOME");
	aux = ft_strjoin(getenv("HOME"), getenv("HOME"));
	TEST_ASSERT_EQUAL_STRING(aux, str);
	free(aux);

	str = expander("$IS_NOT_HOME");
	TEST_ASSERT_EQUAL_STRING("", str);
}
