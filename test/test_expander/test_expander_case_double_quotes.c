# include "../h_test.h"

void	check_expander()
{
	char	*str;
	char	*temp;

	str = expander("$HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), str);
	free(str);

	str = expander("$");
	TEST_ASSERT_EQUAL_STRING("$", str);
	free(str);

	str = expander("oi $SHELL $*$ $ tudo $$ $SHELL $? ?$");
	TEST_ASSERT_EQUAL_STRING("oi /bin/bash $*$ $ tudo $$ /bin/bash $? ?$", str);
	free(str);

	str = expander("$!");
	TEST_ASSERT_EQUAL_STRING("$!", str);
	free(str);

	str = expander("$ $");
	TEST_ASSERT_EQUAL_STRING("$ $", str);
	free(str);

	str = expander("    $HOME");
	temp = ft_strjoin("    ", getenv("HOME"));
	TEST_ASSERT_EQUAL_STRING(temp, str);
	free(temp);
	free(str);

	str = expander("     ");
	TEST_ASSERT_EQUAL_STRING("     ", str);

	str = expander(" ");
	TEST_ASSERT_EQUAL_STRING(" ", str);

	str = expander("");
	TEST_ASSERT_EQUAL_STRING("", str);

	str = expander("$#$#");
	TEST_ASSERT_EQUAL_STRING("$#$#", str);
	free(str);

	str = expander("$$$$");
	TEST_ASSERT_EQUAL_STRING("$$$$", str);
	free(str);

	str = expander("$$");
	TEST_ASSERT_EQUAL_STRING("$$", str);
	free(str);

	str = expander("$SHELL $SHELL");
	TEST_ASSERT_EQUAL_STRING("/bin/bash /bin/bash", str);
	free(str);

	str = expander("$INVALID");
	TEST_ASSERT_EQUAL_STRING("", str);
	free(str);

	str = expander("uname echo uname");
	TEST_ASSERT_EQUAL_STRING("uname echo uname", str);
	
	str = expander("$SHELL$SHELL");
	TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash", str);
	free(str);

	str = expander("$SHELLa");
	TEST_ASSERT_EQUAL_STRING("", str);
	free(str);

	str = expander("uname$SHELL");
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash", str);
	free(str);

	str = expander("$SHELL uname");
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", str);
	free(str);
	
	str = expander("uname$SHELL_INVALIDO");
	TEST_ASSERT_EQUAL_STRING("uname", str);
	free(str);

	str = expander("$SHELL uname");
	TEST_ASSERT_EQUAL_STRING("/bin/bash uname", str);
	free(str);

	str = expander("uname $SHELL");
	TEST_ASSERT_EQUAL_STRING("uname /bin/bash", str);
	free(str);
	
	str = expander("$SHELL");
	TEST_ASSERT_EQUAL_STRING("/bin/bash", str);
	free(str);

	str = expander("uname$SHELL#shell");
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash#shell", str);
	free(str);

	str = expander("'$HOME'");
	TEST_ASSERT_EQUAL_STRING("$HOME", str);
	free(str);

	str = expander("uname$SHELL\"$SHELL\"");
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash\"/bin/bash\"", str);
	free(str);

	str = expander("uname$SHELL\"$SHELL'\"");
	TEST_ASSERT_EQUAL_STRING("uname/bin/bash\"/bin/bash'\"", str);
	free(str);

	str = expander("'$SHELL'"); //
	TEST_ASSERT_EQUAL_STRING("$SHELL", str);
	free(str);

	// str = expander("\"'$SHELL'\""); //
	// TEST_ASSERT_EQUAL_STRING("'/bin/bash'", str);
	// free(str);

	// str = expander("\"uname$SHELL $SHELL'sim'\"");
	// TEST_ASSERT_EQUAL_STRING("uname/bin/bash /bin/bash'sim'", str);
	// free(str);

	// str = expander("\"uname$SHELL'$SHELL'\"");
	// TEST_ASSERT_EQUAL_STRING("uname/bin/bash'/bin/bash'", str);
	// free(str);


	// str = expander("\"$SHELL\"'$SHELL'"); //ESSE NÃO PODE SER USADO NO TESTE, JÁ QUE EXISTEM ->
	// TEST_ASSERT_EQUAL_STRING("/bin/bash$SHELL", str); //DOIS TOKENS AQUI
	// free(str);
}
