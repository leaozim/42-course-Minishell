# include "../h_test.h"

void    check_brace_expansion()
{
	char	*str;

	str = expander("${SHELL}");
	TEST_ASSERT_EQUAL_STRING("/bin/bash", str);
	free(str);

	str = expander("${SHELL}uname");
	TEST_ASSERT_EQUAL_STRING("/bin/bashuname", str);
	free(str);

	str = expander("${SHELL} uname");
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", str);
	free(str);

	str = expander("uname${SHELL}");
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash", str);
	free(str);

	str = expander("uname ${SHELL}");
	TEST_ASSERT_EQUAL_STRING("uname /bin/bash", str);
	free(str);

	str = expander("${SHELL}${SHELL}");
	TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash", str);
	free(str);

	str = expander("${SHELL} ${SHELL}");
	TEST_ASSERT_EQUAL_STRING("/bin/bash /bin/bash", str);
	free(str);

	str = expander("${SHELL }");
	TEST_ASSERT_EQUAL_STRING("", str);
	free(str);

	//touch main.{js,py,ex,r,rs,go,s,rb}
	// str = expander_brace_expansion("main.{js,py,ex,r,rs,go,s,rb}");
	// TEST_ASSERT_EQUAL_STRING("main.js main.py main.ex main.r main.rs main.go main.s main.rb", str);
	// free(str);

	//echo iphone{\ 11,\ 12,\ 13,\ 14}
	// str = expander_brace_expansion("iphone{\\ 11,\\ 12,\\ 13,\\ 14}");
	// TEST_ASSERT_EQUAL_STRING("iphone 11 iphone 12 iphone 13 iphone 14", str);
	// free(str);

}