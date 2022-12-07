#include "../h_test.h"

# define VALOR_SUB '0'
# define VALOR_ORIG ' '

void	checar_espacos_que_nao_serao_salvos(void)
{
	char str[100] = "echo \"oi\"";
	char *str2;

	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING(str, str2);
	free(str2);

	strcpy(str, "echo oi");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING(str, str2);
	free(str2);

	strcpy(str, "echo 'oi'");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING(str, str2);
	free(str2);

	strcpy(str, "echo 'oi' 'humano'");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING(str, str2);
	free(str2);

	strcpy(str, "echo \"oi\" \"humano\"");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING(str, str2);
	free(str2);
}

void	checar_espacos_que_serao_salvos_aspas_simples(void)
{
	char str[100] = "echo \'oi \'";
	char *str2;

	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING("echo \'oi0\'", str2);
	free(str2);

	strcpy(str, "echo 'oi ' 'humano'");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING("echo 'oi0' 'humano'", str2);
	free(str2);

	strcpy(str, "echo ' oi ' ' humano  '");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING("echo '0oi0' '0humano00'", str2);
	free(str2);
	
	strcpy(str, "echo ' oi ' ' humano  '");
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING("echo '0oi0' '0humano00'", str2);
	free(str2);
}

void	checar_espacos_que_serao_salvos_mix(void)
{
	char str[100] = "echo \"oi  \' oi \" \' oi \" \"\' \"  \"  oi   \' oi \'";
	char *str2;
	str2 = ft_strdup(str);
	replace_value_inside_quotes(str2, VALOR_ORIG, VALOR_SUB);
	TEST_ASSERT_EQUAL_STRING("echo \"oi00\'0oi0\" \'0oi0\"0\"\' \"00\"  oi   \'0oi0\'", str2);
	free(str2);
}

void	test_check_replace_value_inside_quotes(void)
{
	RUN_TEST(checar_espacos_que_nao_serao_salvos);
	RUN_TEST(checar_espacos_que_serao_salvos_aspas_simples);
	RUN_TEST(checar_espacos_que_serao_salvos_mix);
}
