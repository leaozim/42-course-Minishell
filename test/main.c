# include "h_test.h"

void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_save_spaces_between_quotes);
	RUN_TEST(test_check_valid_quoting);
	RUN_TEST(test_check_program);
	RUN_TEST(check_token_qtt);
	RUN_TEST(test_add_spaces);
	return UNITY_END();
}
