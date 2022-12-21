# include "../h_test.h"

void	check_expander()
{
	char	*str;
	char	*temp;
	char	*expanded_var;

	str = ft_strdup("$HOME");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("oi $COLORTERM $*$ $ tudo $$ $COLORTERM $? ?$");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("oi truecolor $*$ $ tudo $$ truecolor $? ?$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("    $HOME");
	expanded_var = minishell_expansion(str);
	temp = ft_strjoin("    ", getenv("HOME"));
	TEST_ASSERT_EQUAL_STRING(temp, expanded_var);
	free(temp);
	free(str);
	free(expanded_var);

	str = ft_strdup("$!");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$!", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$ $");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$ $", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("     ");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("     ", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup(" ");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING(" ", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$#$#");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$#$#", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$$$$");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$$$$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$$");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$$", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$COLORTERM $COLORTERM");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor truecolor", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$INVALID");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname echo uname");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("uname echo uname", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("$COLORTERM$COLORTERM");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolortruecolor", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$COLORTERMa");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$COLORTERM");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$COLORTERM uname");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor uname", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("uname$COLORTERM_INVALIDO");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("uname", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("$COLORTERM uname");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor uname", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname $COLORTERM");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("uname truecolor", expanded_var);
	free(str);
	free(expanded_var);
	
	str = ft_strdup("$COLORTERM");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("truecolor", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$COLORTERM#shell");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor#shell", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("'$HOME'");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$HOME", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$COLORTERM\"$COLORTERM\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor\"truecolor\"", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("uname$COLORTERM\"$COLORTERM'\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor\"truecolor'\"", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("'$COLORTERM'");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("$COLORTERM", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"'$COLORTERM'\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("'truecolor'", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"uname$COLORTERM $COLORTERM'sim'\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor truecolor'sim'", expanded_var);
	free(str);
	free(expanded_var);

	str = ft_strdup("\"uname$COLORTERM'$COLORTERM'\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("unametruecolor'truecolor'", expanded_var);
	free(str);
	free(expanded_var);

	// str = ft_strdup("\"$COLORTERM\"'$COLORTERM'"); //ESSE NÃO PODE SER USADO NO TESTE, JÁ QUE EXISTEM ->
	// TEST_ASSERT_EQUAL_STRING("truecolor$COLORTERM", expanded_var); //DOIS TOKENS AQUI
	// free(str);

	str = ft_strdup("\"''\"");
	expanded_var = minishell_expansion(str);
	TEST_ASSERT_EQUAL_STRING("''", expanded_var);
	free(str);
	free(expanded_var);
}
