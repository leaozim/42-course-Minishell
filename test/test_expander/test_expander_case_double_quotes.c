# include "../h_test.h"

void	check_expander()
{
	char	*str;
	char	*temp;
	char	*expanded_var;

	str = ft_strdup("$HOME");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("oi $SHELL $*$ $ tudo $$ $SHELL $? ?$");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("oi /bin/bash $*$ $ tudo $$ /bin/bash $? ?$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("    $HOME");
	expanded_var = expanding_tokens(str);
	temp = ft_strjoin("    ", getenv("HOME"));
	TEST_ASSERT_EQUAL_STRING(temp, expanded_var);
	free(temp);
	free(str);
	free(expanded_var);

	str = ft_strdup("$!");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$!", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$ $");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$ $", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("     ");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("     ", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup(" ");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING(" ", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$#$#");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$#$#", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$$$$");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$$$$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$$");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$SHELL $SHELL");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash /bin/bash", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$INVALID");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname echo uname");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname echo uname", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("$SHELL$SHELL");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$SHELLa");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$SHELL");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$SHELL uname");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("uname$SHELL_INVALIDO");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$SHELL uname");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname $SHELL");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname /bin/bash", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("$SHELL");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("/bin/bash", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$SHELL#shell");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash#shell", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("'$HOME'");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$HOME", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$SHELL\"$SHELL\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash\"/bin/bash\"", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$SHELL\"$SHELL'\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash\"/bin/bash'\"", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("'$SHELL'");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("$SHELL", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"'$SHELL'\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("'/bin/bash'", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"uname$SHELL $SHELL'sim'\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash /bin/bash'sim'", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"uname$SHELL'$SHELL'\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash'/bin/bash'", expanded_var);
	free(str);
	free(expanded_var);

	// str = ft_strdup("\"$SHELL\"'$SHELL'"); //ESSE NÃO PODE SER USADO NO TESTE, JÁ QUE EXISTEM ->
	// TEST_ASSERT_EQUAL_STRING("/bin/bash$SHELL", expanded_var); //DOIS TOKENS AQUI
	// free(str);

	str = ft_strdup("\"''\"");
	expanded_var = expanding_tokens(str);
	TEST_ASSERT_EQUAL_STRING("''", expanded_var);
	free(str);
	free(expanded_var);
}
