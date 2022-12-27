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
	TEST_ASSERT_EQUAL_INT(2, count);
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
	TEST_ASSERT_EQUAL_INT(2, count);
	free(str);

	//27 //PAREI NO TESTE 27
	str = strdup("\"OLA TUDO BEM    \"\"COM VOCE ");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	// str = strdup("\"OLA\"|\"PESSOAL\"");		//tratar redirecionadores | < > << >>
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup("\"OLA\" PESSOAL TUDO\"BEM COM\" \"VOCES\"\"POR AI?\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(6, count);
	// free(str);

	// str = strdup("OLA | PESSOAL");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup("\"OLA\"\"PESSOAL\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("\"OLA\"PESSOAL");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("\"OLA\" PESSOAL");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("OLA \"PESSOAL\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("  OLA \"PESSOAL\"  ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("    \"     \"   ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// //ERRO DE SINTAXE (12 resultados de erros por enquanto)
	// str = strdup("\"OLA\"PESSOAL\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"   ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("    \"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);
	
	// str = strdup("    \"   ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("  \"\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"\"  ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("    \"\"   ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"OLA");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"OLA\" \'");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("     \"OLA         \" \'   \' \"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
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
