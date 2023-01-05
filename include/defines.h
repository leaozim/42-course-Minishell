#ifndef DEFINES_H
# define DEFINES_H

#include <sys/stat.h>
# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define ARROW "> "
# define PROMPT "MiniHELL $"
# define TMP_FILE	"./minishell_temp_file"
# define TOKEN_COUNT 17
# define EQUAL 61
# define TEMP 2
# define INDEX_ZERO 0
# define TERMINATOR -1

# define REPLACE_VALUE 3
# define SPACE ' '
# define MARKER '\x06'

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

// typedef struct s_utils
// {
// 	int			len_tokens;
// 	int			infd;
// 	int			outfd;

// }	t_utils;

// typedef struct s_cmd
// {
// 	int		argc;
// 	char	**argv
// 	char	**envp;

// 	char	*word_token;
// 	char	*redir_token;
// 	char	*in;
// 	char	*out
	
// 	is_builtin
// 	status
// 	pid
// 	pathname
// }	t_cmd;

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
	QUERY = 36,
	APPEND = 2,
	HEREDOC = 3,
	DELIMITER = 4,
	FILE_APPEND = 5,
	FILE_OUT = 600,
	FILE_IN = 601,
};

#endif
