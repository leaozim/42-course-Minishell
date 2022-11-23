#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "MiniHELL $"
# define TOKEN_COUNT 17
# define TEMP 2
# define TEMP_VALUE 3
# define SPACE ' '

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
