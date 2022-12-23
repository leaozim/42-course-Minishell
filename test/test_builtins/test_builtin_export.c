# include "../h_test.h"

void    test_builtin_export()
{
    char	*str;

	str = ft_strdup("OLA");
	TEST_ASSERT_EQUAL_STRING("OLA", str);
	free(str);
}