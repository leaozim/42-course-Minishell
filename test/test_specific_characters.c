# include "h_test.h"

void	check_token_count_squote()
{
	char	*str;

	str = "cat \'oi\' \' \'";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "echo \"oi \' dsdf\' \"";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));
}

void	check_token_count_dquotes()
{
	char	*str;
	
	str = "cat \"oi\" \" \"";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "echo \"oi \' dsdf\' \"";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));
}

void	check_token_count_mixed_quotes()
{
	char	*str;

	str = "cat \"oi\" \' \'";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "cat \"oi         \" \'         \'";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "cat \"oi \' \"";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));

	str = "cat \'oi\" \' ";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));

	str = "cat \"oi\"\'\'";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));
}

void	check_token_count_parallel_quotes()
{
	TEST_ASSERT_EQUAL_INT(8, 8);
	TEST_ASSERT_EQUAL_INT(8, 8);
}

void	check_token_count_detached_quote()
{
	TEST_ASSERT_EQUAL_INT(1, 1);
	TEST_ASSERT_EQUAL_INT(1, 1);
	TEST_ASSERT_EQUAL_INT(5, 5);
}

void	check_token_count_pipe()
{
	char	*str;
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(TOKENS_GENERAL_2));
	
	str = "ls -l | wc -c";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));

	str = "ls -la..|cat -e|wc -l";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "ls -l|wc -c";
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(str));
}

void	check_token_count_greaterthan()
{
	char	*str;

	str = "txt<oi<ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "txt < oi < ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "< oi < ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "< <";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "< < < < < < < < < < <";
	TEST_ASSERT_EQUAL_INT(11, count_tokens_specific(str));

	str = "txt<oi<ls<ks<ksk<kddk<sjsd";
	TEST_ASSERT_EQUAL_INT(6, count_tokens_specific(str));
}

void	check_token_count_lessthan()
{
	char	*str;

	str = "txt>oi>ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "txt > oi > ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "> oi > ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "> >";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "> > > > > > > > > > >";
	TEST_ASSERT_EQUAL_INT(11, count_tokens_specific(str));

	str = "txt>oi>ls>ks>ksk>kddk>sjsd";
	TEST_ASSERT_EQUAL_INT(6, count_tokens_specific(str));
}

void	check_token_count_double_greaterthan()
{
	char	*str;

	str = "txt>>oi>>ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = "txt >> oi >> ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = ">> oi >> ls";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = ">> >>";
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(str));

	str = ">> >> >> >> >> >> >> >> >> >> >>";
	TEST_ASSERT_EQUAL_INT(11, count_tokens_specific(str));

	str = "txt>>oi>>ls>>ks>>ksk>>kddk>>sjsd";
	TEST_ASSERT_EQUAL_INT(6, count_tokens_specific(str));
}

void	check_token_count_double_lessthan()
{
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(3, 3);
}

void	check_token_count_general()
{
	TEST_ASSERT_EQUAL_INT(3, 3);
	TEST_ASSERT_EQUAL_INT(9, 9);
	TEST_ASSERT_EQUAL_INT(13, 13);
}

void	check_token_count_quotes(void)
{
	check_token_count_squote();
	check_token_count_dquotes();
	check_token_count_mixed_quotes();
	check_token_count_parallel_quotes();
	check_token_count_detached_quote();
}

void	check_token_count_redirection(void)
{
	check_token_count_pipe();
	check_token_count_greaterthan();
	check_token_count_lessthan();
	check_token_count_double_greaterthan();
	check_token_count_double_lessthan();
}


void	check_token_count(void)
{
	check_token_count_general();
	check_token_count_quotes();
	check_token_count_redirection();
}

void	check_token_qtt(void)
{
	RUN_TEST(check_token_count);
}