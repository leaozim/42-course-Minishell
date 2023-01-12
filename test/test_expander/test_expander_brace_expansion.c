# include "../h_test.h"

void    check_brace_expansion(void)
{
	char	*str;
	char	*temp;

	str = ft_strdup("${COLORTERM}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor", temp);
	free(str);
	free(temp);

	str = ft_strdup("${COLORTERM}uname");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecoloruname", temp);
	free(str);
	free(temp);

	str = ft_strdup("${COLORTERM} uname");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor uname", temp);
	free(str);
	free(temp);

	str = ft_strdup("uname${COLORTERM}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor", temp);
	free(str);
	free(temp);

	str = ft_strdup("uname ${COLORTERM}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("uname truecolor", temp);
	free(str);
	free(temp);

	str = ft_strdup("${COLORTERM}${COLORTERM}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolortruecolor", temp);
	free(str);
	free(temp);

	str = ft_strdup("${COLORTERM} ${COLORTERM}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor truecolor", temp);
	free(str);
	free(temp);

	str = ft_strdup("${}");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("\"${COLORTERM }\"");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("\"${COLORTERM\"");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("${{");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("\"${\"");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("\"${}\"");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	str = ft_strdup("\"${{\"");
	temp = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	// str = ft_strdup("\"${COLORTERM}\"\"${COLORTERM}\"");
	// temp = minishell_expansion(str);
	// TEST_ASSERT_EQUAL_STRING("truecolortruecolor", temp);
	// free(str);
	// free(temp);

	// //touch main.{js,py,ex,r,rs,go,s,rb}
	// // str = expander_brace_expansion("main.{js,py,ex,r,rs,go,s,rb}");
	// // TEST_ASSERT_EQUAL_STRING("main.js main.py main.ex main.r main.rs main.go main.s main.rb", str);
	// // free(str);

	// //echo iphone{\ 11,\ 12,\ 13,\ 14}
	// // str = expander_brace_expansion("iphone{\\ 11,\\ 12,\\ 13,\\ 14}");
	// // TEST_ASSERT_EQUAL_STRING("iphone 11 iphone 12 iphone 13 iphone 14", str);
	// // free(str);

}