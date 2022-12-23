#include "../h_test.h"

void	test_valid_characters_in_espcific_position(void)
{	
	char *string;
	char *temp;

	temp = ft_strdup("\"oi\"\"oi\"");
	dprintf(2, "string = %s\n", temp);
	string = add_bookmark(temp);
	dprintf(2, "string = %s\n", string);
	TEST_ASSERT_EQUAL_STRING("\"oi\"6\"oi\"", temp);
	// free(str);
	// free(temp);
}

void	add_characters_in_espcific_position()
{
	RUN_TEST(test_valid_characters_in_espcific_position);
}