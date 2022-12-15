#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "MiniHELL $ "
# define TOKEN_COUNT 17
# define TEMP 2

# define REPLACE_VALUE 3
# define SPACE ' '

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
}	t_tokens;
// t_bool	error;

typedef struct s_minishell
{
	char	*prompt_line;
	t_list	*tks;
	char	**tab_tokens;
	int		*tab_id;
	int		len_tokens;
	char	*modified_str;
}	t_minishell;


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