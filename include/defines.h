#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define PROMPT "🔥 MiniHELL $ "
# define CIRCLE "●"
# define TMP_FILE	"./minishell_temp_file"
# define TOKEN_COUNT 17
# define EQUAL 61
# define TEMP 2
# define INDEX_ZERO 0
# define TERMINATOR -1

# define REPLACE_VALUE 3
# define SPACE ' '
# define MARKER '\x06'

# define EXIT_ALONLY 1
# define EXIT_NO_NUMERIC 2
# define EXIT_NUMERIC 3
# define EXIT_TOO_MANY_ARGC 4

# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_tokens
{
	char	*token;
	int		id_token;
	int		index;
	t_bool	err;
}	t_tokens;

typedef struct s_minishell
{
	char		*prompt_line;
	t_list		*tks;
	t_list		*env;
	char		**tab_tokens;
	int			*tab_id;
	char		*line_heredoc;
	int			exit_status;
	int			len_tokens;
	int			infd;
	int			outfd;
	int			fd_heredoc;
}	t_minishell;

t_minishell	g_ms;

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
	QUERY = 36,
	APPEND = 2,
	HEREDOC = 3,
	DELIMITER = 4,
	FILE_APPEND = 5,
	FILE_OUT = 600,
	FILE_IN = 601,
};

#endif
