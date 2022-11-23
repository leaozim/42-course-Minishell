#include "h_defines.h"
#include "h_test.h"

void	test_valid_add_spaces()
{
	TEST_ASSERT_EQUAL_STRING("ls -la ..",
	add_spaces_at_specific_char(TOKENS_GENERAL_1, 0));

	TEST_ASSERT_EQUAL_STRING("ls -la ..  |  cat -e  |  wc -l",
	add_spaces_at_specific_char(TOKENS_GENERAL_2, 2));

	TEST_ASSERT_EQUAL_STRING("export MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minishell",
	add_spaces_at_specific_char(TOKENS_GENERAL_3, 0));

	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  '   '   |    tr  ' '  x  >  outfile",
	add_spaces_at_specific_char(TOKENS_SQUOTE_1, 0));

	TEST_ASSERT_EQUAL_STRING(".gitignore  <  tr ex  ' X'   |  tr pi  'P '   >  outfile",
	add_spaces_at_specific_char(TOKENS_SQUOTE_2, 5));

	TEST_ASSERT_EQUAL_STRING("echo <  ' oi  ' ?$p ' humano  | '  |  >> ",
	add_spaces_at_specific_char(TOKENS_SQUOTE_3, 5));

	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \"   |    tr  \" \"  x  >  outfile",
	add_spaces_at_specific_char(TOKENS_DQUOTES, 1));

	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \"   |    tr  \' \'  x  >  outfile",
	add_spaces_at_specific_char(TOKENS_MIXED_QUOTES, 1));

	TEST_ASSERT_EQUAL_STRING("infile    <  tr a  \"   \' |   tr \' \"  x  >  outfile",
	add_spaces_at_specific_char(TOKENS_PARALLEL_QUOTES_1, 1));

	TEST_ASSERT_EQUAL_STRING("infile    <  tr a    \'  \"   \'   |    tr  \' \"     \'  x  >  outfile",
	add_spaces_at_specific_char(TOKENS_PARALLEL_QUOTES_2, 1));

	TEST_ASSERT_EQUAL_STRING("help |  rg unset",
	add_spaces_at_specific_char(TOKENS_PIPE_1, 1));

	TEST_ASSERT_EQUAL_STRING("help | rg unset",
	add_spaces_at_specific_char(TOKENS_PIPE_2, 1));

	TEST_ASSERT_EQUAL_STRING("ls >  out",
	add_spaces_at_specific_char(TOKENS_GREATERTHAN_1, 1));

	TEST_ASSERT_EQUAL_STRING("ls > out",
	add_spaces_at_specific_char(TOKENS_GREATERTHAN_2, 1));

	TEST_ASSERT_EQUAL_STRING("out < rg .",
	add_spaces_at_specific_char(TOKENS_LESSTHAN_1, 1));

	TEST_ASSERT_EQUAL_STRING("cat < out",
	add_spaces_at_specific_char(TOKENS_LESSTHAN_2, 1));

	TEST_ASSERT_EQUAL_STRING(" < cat out",
	add_spaces_at_specific_char(TOKENS_LESSTHAN_3, 1));

	TEST_ASSERT_EQUAL_STRING(" < out rg  '.' ",
	add_spaces_at_specific_char(TOKENS_LESSTHAN_4, 1));

	TEST_ASSERT_EQUAL_STRING("rg a >> out",
	add_spaces_at_specific_char(TOKENS_DOUBLE_GREATERTHAN, 1));

	TEST_ASSERT_EQUAL_STRING(" << . cat",
	add_spaces_at_specific_char(TOKENS_DOUBLE_LESSTHAN_1, 1));

	TEST_ASSERT_EQUAL_STRING("cat << .",
	add_spaces_at_specific_char(TOKENS_DOUBLE_LESSTHAN_2, 1));



}

void	test_add_spaces()
{
	RUN_TEST(test_valid_add_spaces);
}