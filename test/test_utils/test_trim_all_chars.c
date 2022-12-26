# include "../h_test.h"

void    test_strtrim_allchars(void)
{
    char    *str;
    char    *temp;

    str = "\"OLA=PE\"SSOAL\"\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("OLA=PESSOAL", temp);
    free(temp);

    str = "\"OLA\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("OLA", temp);
    free(temp);

    str = "OLA";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("OLA", temp);
    free(temp);

    str = "\"OLA\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("OLA", temp);
    free(temp);

    str = "\"O\"L\"A\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("OLA", temp);
    free(temp);

    str = "\"L\"A\"\"\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("LA", temp);
    free(temp);

    str = "\"\"L\"\"A\"\"\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("LA", temp);
    free(temp);

    str = "\"\"\"L\"\"\"\"A\"\"\"";
    temp = ft_strtrim_allchars(str, '\"');
    TEST_ASSERT_EQUAL_STRING("LA", temp);
    free(temp);

    str = "_A";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("A", temp);
    free(temp);

    str = "A_";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("A", temp);
    free(temp);

    str = "A_ _ _ _A";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("A   A", temp);
    free(temp);

    str = "_";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("", temp);
    free(temp);

    str = "";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("", temp);
    free(temp);
    
    str = "__________6";
    temp = ft_strtrim_allchars(str, '_');
    TEST_ASSERT_EQUAL_STRING("6", temp);
    free(temp);
}