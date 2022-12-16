# include "../h_test.h"

void    check_brace_expansion()
{
	char	*str;
	char	*temp;

	str = ft_strdup("${SHELL}");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash", temp);
	free(str);
	free(temp);

	str = ft_strdup("${SHELL}uname");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bashuname", temp);
	free(str);
	free(temp);

	str = ft_strdup("${SHELL} uname");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", temp);
	free(str);
	free(temp);

	str = ft_strdup("uname${SHELL}");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash", temp);
	free(str);
	free(temp);

	str = ft_strdup("uname ${SHELL}");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname /bin/bash", temp);
	free(str);
	free(temp);

	str = ft_strdup("${SHELL}${SHELL}");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash", temp);
	free(str);
	free(temp);

	str = ft_strdup("${SHELL} ${SHELL}");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash /bin/bash", temp);
	free(str);
	free(temp);

	str = ft_strdup("${SHELL }");
	temp = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("", temp);
	free(str);
	free(temp);

	//touch main.{js,py,ex,r,rs,go,s,rb}
	// str = expander_brace_expansion("main.{js,py,ex,r,rs,go,s,rb}");
	// TEST_ASSERT_EQUAL_STRING("main.js main.py main.ex main.r main.rs main.go main.s main.rb", str);
	// free(str);

	//echo iphone{\ 11,\ 12,\ 13,\ 14}
	// str = expander_brace_expansion("iphone{\\ 11,\\ 12,\\ 13,\\ 14}");
	// TEST_ASSERT_EQUAL_STRING("iphone 11 iphone 12 iphone 13 iphone 14", str);
	// free(str);

}