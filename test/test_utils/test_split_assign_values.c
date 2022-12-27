# include "../h_test.h"

void	free_char_array_memory(char **my_array)
{
	int	i;

	i = 0;
	if (my_array == NULL || *my_array == NULL)
		return ;
	while (my_array[i] != NULL)
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}

void    test_split_assign_values(void)
{
    char	*str;
	char    **tab;
	char	**expected;
	int		count;

	//0
	count = 1;
	str = strdup("OLA");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//1
	count = 2;
	str = strdup("OLA PESSOAL");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "PESSOAL";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//2
	count = 3;
	str = strdup("OLA PESSOAL TUDO");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "PESSOAL";
	expected[2] = "TUDO";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//3
	count = 4;
	str = strdup("OLA PESSOAL TUDO BEM");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "PESSOAL";
	expected[2] = "TUDO";
	expected[3] = "BEM";
	expected[4] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//4
	count = 1;
	str = strdup(" OLA");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//5
	count = 1;
	str = strdup("OLA ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//6
	count = 1;
	str = strdup("          OLA");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//7
	count = 1;
	str = strdup("          OLA ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//8
	count = 1;
	str = strdup(" OLA ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//9
	count = 1;
	str = strdup("  OLA  ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//10
	count = 2;
	str = strdup("          OLA TUDO");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "TUDO";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//11
	count = 2;
	str = strdup("  OLA  TUDO  ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "TUDO";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//12
	count = 3;
	str = strdup(" OLA TUDO BEM");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "TUDO";
	expected[2] = "BEM";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//13
	count = 3;
	str = strdup(" OLA     TUDO BEM");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "TUDO";
	expected[2] = "BEM";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//14
	count = 0;
	str = strdup("");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
	free(tab);

	//15
	count = 0;
	str = strdup(" ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//16
	count = 0;
	str = strdup("     ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//17
	count = 1;
	str = strdup("\"OLA\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
	free_char_array_memory(tab);
	free(expected);

	//18
	count = 1;
	str = strdup(" \"OLA\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//19
	count = 1;
	str = strdup("\'OLA\'");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\'OLA\'";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//20
	count = 1;
	str = strdup(" \"OLA\" ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//21
	count = 2;
	str = strdup(" \"OLA\" \"TUDO\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "\"TUDO\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//22
	count = 2;
	str = strdup("\"OLA\"PESSOAL");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "PESSOAL";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//23
	count = 1;
	str = strdup(" \"OLA TUDO\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA TUDO\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//24
	count = 1;
	str = strdup(" \"OLA TUDO BEM    COM VOCE\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA TUDO BEM    COM VOCE\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//25
	count = 2;
	str = strdup("\"OLA TUDO BEM    \" \"COM VOCE\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA TUDO BEM    \"";
	expected[1] = "\"COM VOCE\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//26
	count = 2;
	str = strdup("\"OLA TUDO BEM    \"\"COM VOCE\" ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA TUDO BEM    \"";
	expected[1] = "\"COM VOCE\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	// //27 //PAREI AQUI NO TESTE 27
	// count = 1;
	// str = strdup("\"OLA TUDO BEM    \"\"COM VOCE ");
	// tab = split_assign_values(str, ' ', count);
	// expected = ft_calloc(count + 1, sizeof(char *));
	// expected[0] = "\"OLA TUDO BEM    \"";
	// expected[1] = NULL;
	// TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	// free(str);
    // free_char_array_memory(tab);
	// free(expected);
}