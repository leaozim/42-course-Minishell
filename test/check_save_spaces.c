# include <test.h>

void    checar_espacos_que_nao_serao_salvos(void)
{
    char str[100] = "echo \"oi\"";
    char *str2;

    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING(str, str2);
    free(str2);

    strcpy(str, "echo oi");
    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING(str, str2);
    free(str2);

    strcpy(str, "echo 'oi'");
    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING(str, str2);
    free(str2);

    strcpy(str, "echo 'oi' 'humano'");
    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING(str, str2);
    free(str2);

    strcpy(str, "echo \"oi\" \"humano\"");
    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING(str, str2);
    free(str2);

}

void    checar_espacos_que_serao_salvos_aspas_simples(void)
{
    char str[100] = "echo \'oi \'";
    char *str2;

    str2 = ft_strdup(str);
    handle_quoting(str2, ' ', '0');
    TEST_ASSERT_EQUAL_STRING("echo \'oi0\'", str2);
    free(str2);
}



void    test_check_spaces(void)
{
    RUN_TEST(checar_espacos_que_nao_serao_salvos);
    RUN_TEST(checar_espacos_que_serao_salvos_aspas_simples);
}
