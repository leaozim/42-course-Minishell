# include "../h_test.h"

void    test_split_count_words(void)
{
    char	*str;
	int		count;

	str = strdup("OLA");
	count = split_count_words(str, ' ');
	TEST_ASSERT_EQUAL_INT(1, count);
	free(str);

	// str = strdup("OLA PESSOAL");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("OLA PESSOAL TUDO");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup("OLA PESSOAL TUDO BEM");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(4, count);
	// free(str);

	// str = strdup(" OLA");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("OLA ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("          OLA");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("          OLA ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("          OLA TUDO");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup(" OLA ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("  OLA  ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("  OLA  TUDO  ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup(" OLA TUDO BEM");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup(" OLA TUDO BEM ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup(" OLA     TUDO BEM");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(3, count);
	// free(str);

	// str = strdup("");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup(" ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("     ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(0, count);
	// free(str);

	// str = strdup("\"OLA\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup(" \"OLA\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup(" \"OLA\" ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup(" \"OLA\" \"TUDO\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("\"OLA\"PESSOAL");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup(" \"OLA TUDO\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup(" \"OLA TUDO BEM    COM VOCE\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(1, count);
	// free(str);

	// str = strdup("\"OLA TUDO BEM    \" \"COM VOCE\"");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

	// str = strdup("\"OLA TUDO BEM    \"\"COM VOCE\" ");
	// count = split_count_words(str, ' ');
	// TEST_ASSERT_EQUAL_INT(2, count);
	// free(str);

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
