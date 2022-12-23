#include "../h_test.h"

void	test_valid_characters_in_espcific_position(void)
{	
	char *string;

	string = ft_strdup("\"oi\"\"oi\"");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\"oi\"\x06\"oi\"", string);
	free(string);

	string = ft_strdup("\"oi\"oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\"oi\"\x06oi", string);
	free(string);

	string = ft_strdup("\'oi\'oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\'oi\'\x06oi", string);
	free(string);

	string = ft_strdup("\'oi\'\'oi\'");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\'oi\'\x06\'oi\'", string);
	free(string);
}
void test_invalid_characters_in_espcific_position(void)
{
	char *string;

	string = ft_strdup("\"oi\" \"oi\"");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\"oi\" \"oi\"", string);
	free(string);

	string = ft_strdup("\"oi\" oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\"oi\" oi", string);
	free(string);

	string = ft_strdup("\'oi\' oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\'oi\' oi", string);
	free(string);

	string = ft_strdup("\'oi\' \'oi\'");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("\'oi\' \'oi\'", string);
	free(string);

	string = ft_strdup("oi oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("oi oi", string);
	free(string);

	string = ft_strdup("oi | oi");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("oi | oi", string);
	free(string);
	
	string = ft_strdup("|oi|oi|");
	string = add_marker(string);
	TEST_ASSERT_EQUAL_STRING("|oi|oi|", string);
	free(string);
}

void	add_characters_in_espcific_position()
{
	RUN_TEST(test_valid_characters_in_espcific_position);
	RUN_TEST(test_invalid_characters_in_espcific_position);
}