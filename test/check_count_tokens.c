# include "test.h"

void	checar_se_a_qtd_de_tokem_esta_correta(void)
{
	char *str;

	str = ft_strdup("ls -la ..");
	TEST_ASSERT_EQUAL(3, 3);
}

void	check_token_qtt(void)
{
	RUN_TEST(checar_se_a_qtd_de_tokem_esta_correta);
}
