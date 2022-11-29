#include "h_test.h"

void	test_valid_add_spaces()
{
	char *str;

	str = add_spaces_specific_tokens(TOKENS_GENERAL_1, 0);
	TEST_ASSERT_EQUAL_STRING("ls -la ..", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_GENERAL_2, 2);
	TEST_ASSERT_EQUAL_STRING("ls -la ..  |  cat -e  |  wc -l", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_GENERAL_3, 0);
	TEST_ASSERT_EQUAL_STRING("export MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minishell", str);	
	free(str);

	str = add_spaces_specific_tokens(TOKENS_SQUOTE_1, 7);
	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  '   '   |    tr  ' '  x  >  outfile", str);
	free (str);

	str = add_spaces_specific_tokens(TOKENS_SQUOTE_2, 5);
	TEST_ASSERT_EQUAL_STRING(".gitignore  <  tr ex  ' X'   |  tr pi  'P '   >  outfile", str);
	free(str);
	
	str = add_spaces_specific_tokens(TOKENS_SQUOTE_3, 5);
	TEST_ASSERT_EQUAL_STRING("echo <  ' oi  ' ?$p ' humano  | '  |  >> ", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_DQUOTES, 5);
	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \"   |    tr  \" \"  x  >  outfile", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_MIXED_QUOTES, 5);
	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \"   |    tr  \' \'  x  >  outfile", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_PARALLEL_QUOTES_1, 3);
	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \' |   tr \' \"  x  >  outfile", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_PARALLEL_QUOTES_2, 5);
	TEST_ASSERT_EQUAL_STRING("infile    <  tr a    \'  \"   \'   |    tr  \' \"     \'  x  >  outfile", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_PIPE_1, 1);
	TEST_ASSERT_EQUAL_STRING("help |  rg unset", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_PIPE_2, 1);
	TEST_ASSERT_EQUAL_STRING("help | rg unset", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_GREATERTHAN_1, 1);
	TEST_ASSERT_EQUAL_STRING("ls >  out", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_GREATERTHAN_2, 1);
	TEST_ASSERT_EQUAL_STRING("ls > out", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_LESSTHAN_1, 1);
	TEST_ASSERT_EQUAL_STRING("out < rg .", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_LESSTHAN_2, 1);
	TEST_ASSERT_EQUAL_STRING("cat < out", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_LESSTHAN_3, 1);
	TEST_ASSERT_EQUAL_STRING(" < cat out", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_LESSTHAN_4, 2);
	TEST_ASSERT_EQUAL_STRING(" < out rg  '.' ",str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_DOUBLE_GREATERTHAN, 1);
	TEST_ASSERT_EQUAL_STRING("rg a >> out", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_DOUBLE_LESSTHAN_1, 1);
	TEST_ASSERT_EQUAL_STRING(" << . cat", str);
	free(str);

	str = add_spaces_specific_tokens(TOKENS_DOUBLE_LESSTHAN_2, 1);
	TEST_ASSERT_EQUAL_STRING("cat << .", str);
	free(str);
}

void	test_add_spaces()
{
	RUN_TEST(test_valid_add_spaces);
}