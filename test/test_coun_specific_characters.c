#include "h_defines.h"
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
	TEST_ASSERT_EQUAL_INT(5, count_tokens_specific(TOKENS_DQUOTES));
}

void	check_token_count_parallel_quotes()
{
	TEST_ASSERT_EQUAL_INT(3, count_tokens_specific(TOKENS_PARALLEL_QUOTES_1));
	TEST_ASSERT_EQUAL_INT(5, count_tokens_specific(TOKENS_PARALLEL_QUOTES_2));
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
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_PIPE_1));
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_PIPE_2));
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
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_GREATERTHAN_1));
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_GREATERTHAN_2));
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
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_LESSTHAN_1));
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_LESSTHAN_2));
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_LESSTHAN_3));
	
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
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_DOUBLE_GREATERTHAN));
}

void	check_token_count_double_lessthan()
{
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_DOUBLE_LESSTHAN_1));
	TEST_ASSERT_EQUAL_INT(1, count_tokens_specific(TOKENS_DOUBLE_LESSTHAN_2));
}

void	check_token_count_mixe()
{
	TEST_ASSERT_EQUAL_INT(0, count_tokens_specific(TOKENS_GENERAL_1));
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(TOKENS_GENERAL_2));
	TEST_ASSERT_EQUAL_INT(0, count_tokens_specific(TOKENS_GENERAL_3));
	TEST_ASSERT_EQUAL_INT(5, count_tokens_specific(TOKENS_SQUOTE_1));
	TEST_ASSERT_EQUAL_INT(5, count_tokens_specific(TOKENS_SQUOTE_2));
	TEST_ASSERT_EQUAL_INT(2, count_tokens_specific(TOKENS_LESSTHAN_4));
	TEST_ASSERT_EQUAL_INT(5, count_tokens_specific(TOKENS_MIXED_QUOTES));
}

void	check_token_count_quotes(void)
{
	check_token_count_squote();
	check_token_count_dquotes();
	check_token_count_mixed_quotes();
	check_token_count_parallel_quotes();
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
	check_token_count_mixe();
	check_token_count_quotes();
	check_token_count_redirection();
}

void	check_token_qtt(void)
{
	RUN_TEST(check_token_count);
}