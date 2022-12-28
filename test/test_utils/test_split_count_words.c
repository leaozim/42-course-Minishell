# include "../h_test.h"

void    test_split_count_words(void)
{
    char	*str;
	int		count;

	//0
	str = strdup("OLA");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//1
	str = strdup("OLA PESSOAL");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//teste
	str = strdup("\"OLA\"\"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//2
	str = strdup("OLA PESSOAL TUDO");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//3
	str = strdup("OLA PESSOAL TUDO BEM");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//4
	str = strdup(" OLA");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//5
	str = strdup("OLA ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//6
	str = strdup("          OLA");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//7
	str = strdup("          OLA ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//8
	str = strdup(" OLA ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//9
	str = strdup("  OLA  ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//10
	str = strdup("          OLA TUDO");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//11
	str = strdup("  OLA  TUDO  ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//12
	str = strdup(" OLA TUDO BEM");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//13
	str = strdup(" OLA     TUDO BEM");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//14
	str = strdup("");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//15
	str = strdup(" ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//16
	str = strdup("     ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//17
	str = strdup("\"OLA\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//18
	str = strdup(" \"OLA\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//19
	str = strdup(" \'OLA\'");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//20
	str = strdup(" \"OLA\" ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//21
	str = strdup(" \"OLA\" \"TUDO\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//22
	str = strdup("\"OLA\"PESSOAL");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//23
	str = strdup(" \"OLA TUDO\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//24
	str = strdup(" \"OLA TUDO BEM    COM VOCE\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//25
	str = strdup("\"OLA TUDO BEM    \" \"COM VOCE\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//26
	str = strdup("\"OLA TUDO BEM    \"\"COM VOCE\" ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//27
	str = strdup("\"OLA PESSOAL COMO    \"\"VOCES ESTAO? ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//28
	str = strdup("\"OLA TUDO BEM    \"\"COM VOCE ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//29
	str = strdup("\"OLA\"|\"PESSOAL\"");		//ola||mundo
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//30
	str = strdup("\"OLA\"||\"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//31
	str = strdup("\"OLA\"|| \"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//32
	str = strdup("\"OLA\" ||\"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//33
	str = strdup("\"A\"\"B\"\"C\"\"D\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//34
	str = strdup("\"A\"\"B\" \'\"C\"\"D\"\'    \'");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//35
	str = strdup("\"OLA\" PESSOAL TUDO\"BEM COM\" \"VOCES\"\"POR AI?\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//36
	str = strdup("OLA | PESSOAL");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//37
	str = strdup("\"OLA\"\"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//38
	str = strdup("\"OLA\"PESSOAL");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//39
	str = strdup("\"OLA\" PESSOAL");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//40
	str = strdup("OLA \"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//41
	str = strdup("  OLA \"PESSOAL\"  ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//42
	str = strdup("    \"     \"   ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);


	//ERRO DE SINTAXE (12 resultados de erros por enquanto)
	//43
	str = strdup("\"OLA\"PESSOAL\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//44
	str = strdup("\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//45
	str = strdup("\"   ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//46
	str = strdup("    \"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//47	
	str = strdup("    \"   ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//48
	str = strdup("\"\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//49
	str = strdup("  \"\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//50
	str = strdup("\"\"  ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//51
	str = strdup("    \"\"   ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//52
	str = strdup("\"OLA");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(0, count);
	free(str);

	//53
	str = strdup("\"OLA\" \'");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//54
	str = strdup("     \"OLA         \" \'   \' \"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//55
	str = strdup("echo Oi\"oi\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//56
	str = strdup("\"oi\"\"oi\"\"oi\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//57
	str = strdup("\"oi\"oi\"oo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//58
	str = strdup("\"oi\"iajanjka");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//59
	str = strdup("jszkdjfs\"oi\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//60
	str = strdup("echo\"oi\"\"oi\"\"oiu\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	str = strdup("echo \"oi\"\"oi\"\"oiu\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//61
	str = strdup("ola||mundo");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//62
	str = strdup("\"ola\"uname|uname\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//63
	str = strdup("\"ola\"a|\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//64
	str = strdup("\"ola\"<<\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//65
	str = strdup("\"ola\"< <\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//66
	str = strdup("ola< <mundo");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	//67
	str = strdup("ola<<mundo");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(3, count);
	free(str);

	//69
	str = strdup("\"ola\"\"|\"\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	//70
	str = strdup("\"ola\"\"||\"\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	str = strdup("\"ola\"||\"mundo\"");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(4, count);
	free(str);

	str = strdup("<");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	// str = strdup("<<");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("<<<<");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("<<<<<");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);
	
	// str = strdup("<<<");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);




	//
	// str = strdup("\"\"\'\'\"\"\'\'OLA");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);
}

//RASCUNHO


//"OLA" PESSOAL TUDO"BEM COM" "VOCES""POR AI?"

// int	update_strlen_to_quote_removal(char	*str)
// {
// 	int	i;
// 	int	new_len;

// 	i = 0;
// 	new_len = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == SQUOTE || str[i] == DQUOTES)
// 		{
// 			if (count_quotes_pair(str, str[i], &i) == FALSE)
// 				return (-1);
// 			new_len++;
// 		}
// 		i++;
// 	}
// 	return (new_len);
// }

// int	*set_positions_quote_removal(char *str, int terminator)
// {
// 	int	i;
// 	int	j;
// 	int	*positions;
// 	int	count;

// 	count = update_strlen_to_quote_removal(str);
// 	if (count == -1)
// 		return (NULL);
// 	positions = ft_calloc((count * 2) + 1, sizeof(int));
// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == SQUOTE || str[i] == DQUOTES)
// 		{
// 			positions[j] = i;
// 			j++;
// 			count_quotes_pair(str, str[i], &i);
// 			positions[j] = i;
// 			j++;
// 		}
// 		i++;
// 	}
// 	positions[j] = terminator;
// 	return (positions);
// }


// char	*ft_strtrim_specific_pos(char *str, int *pos, int term)
// {
// 	char	*dest;
// 	int		i;
// 	int		j;
// 	int		k;

// 	k = ft_strlen(str) - ft_intarray_len(pos, term);
// 	dest = ft_calloc(k + 1, sizeof(char));
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (i < (int)ft_strlen(str))
// 	{
// 		while (i == pos[k])
// 		{
// 			i++;
// 			k++;
// 		}
// 		dest[j] = str[i];
// 		j++;
// 		i++;
// 	}
// 	return (dest);
// }
