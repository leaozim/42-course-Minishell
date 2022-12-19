#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "MiniHELL $ "
# define TOKEN_COUNT 17
# define TEMP 2
# define TMP_FILE	"./minishell_temp_file"

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

# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_tokens
{
	char	*tokens;
	int		id_tks;
	t_bool	err;
}	t_tokens;

typedef struct s_minishell
{
	char	*prompt_line;
	t_list	*tks;
	char	**tab_tokens;
	int		*tab_id;
	int		exit;
	char	*line_heredoc;
	int		len_tokens;
	char	*modified_str;
	int		infd;
	int		outfd;
}	t_minishell;

t_minishell ms;

enum e_tokens
{
	COMMAND = 1,
	DQUOTES = 34,
	DOLLAR_SIGN = 36,
	SQUOTE = 39,
	SEMICOLON = 59,
	RDRCT_IN = 60,
	RDRCT_OU = 62,
	PIPE = 124,
	QUERY = 63,
	APPEND = 2,
	HEREDOC = 3,
	DELIMITER = 4,
	FILE_APPEND = 5,
	FILE_OUT = 600,
	FILE_IN = 601,
};

#endif
