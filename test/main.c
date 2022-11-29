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
	RUN_TEST(check_identify_tokens);
  
	return UNITY_END();
}
