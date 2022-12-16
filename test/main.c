# include "h_test.h"
#include "unity/unity_internals.h"

void setUp(void)
{

}

void tearDown(void)
{

}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_check_replace_value_inside_quotes);
	RUN_TEST(test_check_valid_quoting);
	RUN_TEST(test_check_program);
	RUN_TEST(check_token_qtt);
	RUN_TEST(test_add_spaces);
	RUN_TEST(check_identify_tokens);
	RUN_TEST(check_repl);
	RUN_TEST(check_valid_expansion);
	RUN_TEST(test_error_syntax_single_metachacacter);
	RUN_TEST(test_error_syntax_consecutive_metachacacter);
	RUN_TEST(test_is_error_syntax_metachacacter);
	RUN_TEST(test_open_files);
	return UNITY_END();
}
