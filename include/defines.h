#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "MiniHELL $"
# define TOKEN_COUNT 17
# define TEMP 2

# define REPLACE_VALUE 3
# define SPACE ' '

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


typedef struct s_minishell
{
	char	*prompt_line;
	char	**tokens;
	int		qtt_tokens;
	char	*str_with_spaces;

} t_minishell;

enum e_tokens
{
	COMMAND = 1,
	DQUOTES = '"',
	DOLLAR_SIGN = '$',
	SQUOTE = '\'',
	SEMICOLON = ';',
	LESSTHAN = '<',
	GREATERTHAN = '>',
	PIPE = '|',
	QUERY = '?',
};

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

#endif
