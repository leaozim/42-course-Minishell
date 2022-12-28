# include "../h_test.h"

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

	//27
	count = 1;
	str = strdup("\"OLA PESSOAL COMO    \"\"VOCES ESTAO? ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA PESSOAL COMO    \"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//28
	count = 1;
	str = strdup("\"OLA TUDO BEM    \"\"COM VOCE ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA TUDO BEM    \"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//29
	count = 3;
	str = strdup("\"OLA\"|\"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "|";
	expected[2] = "\"PESSOAL\"";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//30
	count = 3;
	str = strdup("\"OLA\"||\"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "||";
	expected[2] = "\"PESSOAL\"";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//31
	count = 3;
	str = strdup("\"OLA\"|| \"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "||";
	expected[2] = "\"PESSOAL\"";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//32
	count = 3;
	str = strdup("\"OLA\" ||\"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "||";
	expected[2] = "\"PESSOAL\"";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//33
	count = 4;
	str = strdup("\"A\"\"B\"\"C\"\"D\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"A\"";
	expected[1] = "\"B\"";
	expected[2] = "\"C\"";
	expected[3] = "\"D\"";
	expected[4] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//34
	count = 3;
	str = strdup("\"A\"\"B\" \'\"C\"\"D\"\'    \'");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"A\"";
	expected[1] = "\"B\"";
	expected[2] = "\'\"C\"\"D\"\'";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//35
	count = 6;
	str = strdup("\"OLA\" PESSOAL TUDO\"BEM COM\" \"VOCES\"\"POR AI?\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "PESSOAL";
	expected[2] = "TUDO";
	expected[3] = "\"BEM COM\"";
	expected[4] = "\"VOCES\"";
	expected[5] = "\"POR AI?\"";
	expected[6] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//36
	count = 3;
	str = strdup("OLA | PESSOAL");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "|";
	expected[2] = "PESSOAL";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//37
	count = 2;
	str = strdup("\"OLA\"\"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "\"PESSOAL\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//38
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

	//39
	count = 2;
	str = strdup("\"OLA\" PESSOAL");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "PESSOAL";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//40
	count = 2;
	str = strdup("OLA \"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "\"PESSOAL\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//41
	count = 2;
	str = strdup("  OLA \"PESSOAL\"  ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "OLA";
	expected[1] = "\"PESSOAL\"";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//42
	count = 1;
	str = strdup("    \"     \"   ");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"     \"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//43
	count = 2;
	str = strdup("\"OLA\"PESSOAL\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = "PESSOAL";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//44
	count = 0;
	str = strdup("\"");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//45
	count = 0;
	str = strdup("\"   ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//46
	count = 0;
	str = strdup("    \"");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//47
	count = 0;
	str = strdup("    \"   ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//48
	count = 0;
	str = strdup("\"\"");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//49
	count = 0;
	str = strdup("  \"\"");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//50
	count = 0;
	str = strdup("\"\"  ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//51
	count = 0;
	str = strdup("    \"\"   ");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//52
	count = 0;
	str = strdup("\"OLA");
	tab = split_assign_values(str, ' ', count);
	TEST_ASSERT_EQUAL_STRING("", tab);
	free(str);
    free(tab);

	//53
	count = 1;
	str = strdup("\"OLA\" \'");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA\"";
	expected[1] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//54
	count = 2;
	str = strdup("     \"OLA         \" \'   \' \"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"OLA         \"";
	expected[1] = "\'   \'";
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//55
	count = 3;
	str = strdup("echo Oi\"oi\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "echo";
	expected[1] = "Oi";
	expected[2] = "\"oi\"";
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//56
	count = 3;
	str = strdup("\"oi\"\"oi\"\"oi\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"oi\"";
	expected[1] = "\"oi\"";
	expected[2] = "\"oi\"";	
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//57
	count = 3;
	str = strdup("\"oi\"oi\"oo\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"oi\"";
	expected[1] = "oi";
	expected[2] = "\"oo\"";	
	expected[3] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//58
	count = 2;
	str = strdup("\"oi\"iajanjka");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "\"oi\"";
	expected[1] = "iajanjka";	
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//59
	count = 2;
	str = strdup("jszkdjfs\"oi\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "jszkdjfs";
	expected[1] = "\"oi\"";	
	expected[2] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	//60
	count = 4;
	str = strdup("echo \"oi\"\"oi\"\"oiu\"");
	tab = split_assign_values(str, ' ', count);
	expected = ft_calloc(count + 1, sizeof(char *));
	expected[0] = "echo";
	expected[1] = "\"oi\"";
	expected[2] = "\"oi\"";
	expected[3] = "\"oiu\"";
	expected[4] = NULL;
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	free(str);
    free_char_array_memory(tab);
	free(expected);

	// //55
	// count = 1;
	// str = strdup("\"''\"");
	// tab = split_assign_values(str, ' ', count);
	// expected = ft_calloc(count + 1, sizeof(char *));
	// expected[0] = "\"''\"";
	// expected[1] = NULL;
	// TEST_ASSERT_EQUAL_STRING_ARRAY(expected, tab, count);
	// free(str);
    // free_char_array_memory(tab);
	// free(expected);
	
	//\"''\"
	//\'""\'
	//\'""""""\'
	//\"''''''\"
	//"\"\"\'\'\"\"\'\'
	//"\"\"\'\'\"\"\'\'OLA
	//"\"\"\'OLA\'\"\"\'\'
	//"OLA\"\"\'\'\"\"\'\'
	//"\"OLA\"\'OLA\'\"\"\'\'
}