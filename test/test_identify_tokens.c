#include "h_test.h"

void	ckeck_token_quoting()
{
	int	id_array[2] = {COMMAND, 34};
	int *id_tokens;

	id_tokens = identify_tokens((char *[]){"echo", "\"oi\"", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array, id_tokens, 2);
	free(id_tokens);

	int id_array1[2] = {34, 34};
	id_tokens = identify_tokens((char *[]){"\"echo\"", "\"oi\"", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array1, id_tokens, 2);
	free(id_tokens);

	int id_array2[2] = {39, 39};
	id_tokens = identify_tokens((char *[]){"\'echo\'", "\'oi\'", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array2, id_tokens, 2);
	free(id_tokens);

	int id_array3[2] = {34, 39};
	id_tokens = identify_tokens((char *[]){"\"echo\"", "\'oi\'", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array3, id_tokens, 2);
	free(id_tokens);
}

void	ckeck_token_redirct()
{
	int	id_array[2] = {COMMAND, APPEND};
	int *id_tokens;

	id_tokens = identify_tokens((char *[]){"echo", ">>", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array, id_tokens, 2);
	free(id_tokens);

	int	id_array2[2] = {COMMAND, 3};
	id_tokens = identify_tokens((char *[]){"echo", "<<", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array2, id_tokens, 2);
	free(id_tokens);

	int	id_array3[2] = {2, 3};
	id_tokens = identify_tokens((char *[]){">>", "<<", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array3, id_tokens, 2);
	free(id_tokens);

	int	id_array4[2] = {RDRCT_IN, HEREDOC};
	id_tokens = identify_tokens((char *[]){"<", "<<", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array4, id_tokens, 2);
	free(id_tokens);

	int	id_array5[2] = {RDRCT_OU, HEREDOC};
	id_tokens = identify_tokens((char *[]){">", "<<", NULL}, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array5, id_tokens, 2);
	free(id_tokens);
	
	int	id_array6[4] = {RDRCT_OU, HEREDOC, APPEND, RDRCT_IN};
	id_tokens = identify_tokens((char *[]){">", "<<", ">>", "<", NULL}, 4);
	TEST_ASSERT_EQUAL_INT_ARRAY(id_array6, id_tokens, 4);
	free(id_tokens);
}
void	ckeck_token_()
{

}
void	check_identify_tokens(void)
{
	RUN_TEST(ckeck_token_quoting);
	RUN_TEST(ckeck_token_redirct);

}