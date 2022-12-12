# include "../h_test.h"

// "$EDITOR"
//=> "nano"
# define TOKENS_ENVAR_GENERAL "bar$EDITOR"
//=> "barnano"

//export foo=42
# define TOKENS_ENVAR_SQUOTE_1 "'$foo'"
//=> "'$foo'"

# define TOKENS_ENVAR_SQUOTE_2 "baz$foo'bar'"
//=> "baz42'bar'"

# define TOKENS_ENVAR_SQUOTE_3 "baz$foo'$foo'"
//=> "baz42'$foo'"

# define TOKENS_ENVAR_DQUOTES_1 "\"$foo\""
//=> "\"42\""

# define TOKENS_ENVAR_DQUOTES_2 "baz$foo\"$foo\""
//=> "baz42\"42\""

# define TOKENS_ENVAR_MIXED_QUOTES_1 "baz$foo\"$foo'\""
//=> "baz42\"42'\""

# define TOKENS_ENVAR_MIXED_QUOTES_2 "\"baz$foo'$foo'\""
//=> "\"baz42'42'\""

# define TOKENS_ENVAR_MIXED_QUOTES_3 "'baz$foo'$foo''"
//=> "'baz$foo'42''"

//foo=42
# define TOKENS_ENVAR_LOCAL_1 "$foo"
// => "42"

# define TOKENS_ENVAR_LOCAL_2 "bar$foo"
// => "bar42"

void	check_expander()
{
	char	*str;
	char	*temp;

	str = expand_variables("$HOME");
	TEST_ASSERT_EQUAL_STRING(getenv("HOME"), str);
	free(str);

	str = expand_variables("oi $SHELL $*$ $ tudo $$ $SHELL $? ?$");
	TEST_ASSERT_EQUAL_STRING("oi /bin/bash $*$ $ tudo $$ /bin/bash $? ?$", str);
	free(str);

	str = expand_variables("$");
	TEST_ASSERT_EQUAL_STRING("$", str);
	free(str);

	str = expand_variables("$!");
	TEST_ASSERT_EQUAL_STRING("$", str);
	free(str);

	str = expand_variables("$ $");
	TEST_ASSERT_EQUAL_STRING("$ $", str);
	free(str);

	str = expand_variables("    $HOME");
	temp = ft_strjoin("    ", getenv("HOME"));
	TEST_ASSERT_EQUAL_STRING(temp, str);
	free(temp);
	free(str);

	str = expand_variables("     ");
	TEST_ASSERT_EQUAL_STRING("     ", str);

	str = expand_variables(" ");
	TEST_ASSERT_EQUAL_STRING(" ", str);

	str = expand_variables("");
	TEST_ASSERT_EQUAL_STRING("", str);
	free(str);

	str = expand_variables("$#$#");
	TEST_ASSERT_EQUAL_STRING("$#$", str);
	free(str);

	str = expand_variables("$$$$");
	TEST_ASSERT_EQUAL_STRING("$$$$", str);
	free(str);

	str = expand_variables("$$");
	TEST_ASSERT_EQUAL_STRING("$$", str);
	free(str);

	str = expand_variables("$SHELL $SHELL");
	TEST_ASSERT_EQUAL_STRING("/bin/bash /bin/bash", str);
	free(str);

	str = expand_variables("$INVALID");
	TEST_ASSERT_EQUAL_STRING("", str);
	free(str);

	str = expand_variables("uname echo uname");
	TEST_ASSERT_EQUAL_STRING("uname echo uname", str);
	
	str = expand_variables("$SHELL$SHELL");
	TEST_ASSERT_EQUAL_STRING("/bin/bash/bin/bash", str);
	free(str);
}