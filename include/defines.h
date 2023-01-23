/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:15 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:35:01 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127

# define ARROW "> "
# define PROMPT "🔥 MiniHELL$ "
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

typedef struct s_arguments
{
	char		*argv;
	int			id_argv;
}	t_arguments;

typedef struct s_tokens
{
	char	*token;
	int		id_token;
	int		index;
	t_bool	err;
}	t_tokens;

typedef struct s_commands
{
	int			*id;
	int			infd;
	int			outfd;
	int			pid_fd;
	char		**tks;
	char		*path;
	char		**envp;
	char		**argv;
	char		**cmd_list;
	char		**envp_path;
	t_bool		rdc_in;
	t_bool		rdc_out;
	t_bool		rdc_out_app;
	t_bool		rdc_heredoc;
	t_bool		error_file;
	t_list		*argv_list;
	t_list		*builtins_cmd_list;
	t_tokens	*token_list;
	t_arguments	*arguments;
}	t_commands;

typedef struct s_minishell
{
	int			sig;
	int			*tab_id;
	int			*pid_fd;
	int			num_cmds;
	int			cmd_count;
	int			num_pipes;
	int			**array_fd;
	int			len_tokens;
	int			fd_heredoc;
	int			exit_status;
	int			size_node_builtin;
	char		**tab_tokens;
	char		*prompt_line;
	char		*line_heredoc;
	t_list		*tks;
	t_list		*env;
	t_list		*free_me;
	t_list		*commands;
	t_list		*cmd_table;
	t_commands	cmd_data;
	t_commands	*cmd;
}	t_minishell;

extern t_minishell	g_ms;

enum e_tokens
{
	COMMAND = 1,
	DQUOTES = 34,
	DOLLAR_SIGN = 36,
	SQUOTE = 39,
	SLASH = 47,
	SEMICOLON = 59,
	RDRCT_IN = 60,
	RDRCT_OU = 62,
	QUERY = 63,
	PIPE = 124,
	APPEND = 2,
	HEREDOC = 3,
	DELIMITER = 4,
	FILE_APPEND = 5,
	FILE_OUT = 600,
	FILE_IN = 601,
};

#endif
