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
	RUN_TEST(test_error_syntax_single_metachacacter);
	RUN_TEST(test_error_syntax_consecutive_metachacacter);
	RUN_TEST(check_expander);
	RUN_TEST(check_brace_expansion);
	RUN_TEST(check_repl);
	RUN_TEST(test_is_error_syntax_metachacacter);
	RUN_TEST(test_open_files);
	RUN_TEST(test_builtin_export);
	RUN_TEST(test_strtrim_allchars);
	RUN_TEST(test_split_count_words);
	RUN_TEST(test_split_assign_values);
	// RUN_TEST(add_characters_in_espcific_position);
	return (UNITY_END());
}
