#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "MiniHELL $ "
# define TOKEN_COUNT 17
# define TEMP 2

# define REPLACE_VALUE 3
# define SPACE ' '

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_minishell
{
	char	*prompt_line;
}	t_minishell;

typedef struct s_lexer
{
	char	**tokens;
	int		qtt_tokens;
	char	*str_spcs;
	char	**tab_tokens;
	char	*tab_id;
	int		len_tab;
}	t_lexer;

typedef struct s_tokens
{
	char	*tokens;
	int		id_tks;
	t_bool	error;
}	t_tokens;

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
	HEREDOC  = 3,
};

#endif
