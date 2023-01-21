#include "../../include/minishell.h"

void	open_infile(char *file_tks, int flags, int *infd, t_bool *error)
{
	*infd = open(file_tks, flags);
	if (*infd == -1)
		msg_error_open_file(file_tks, error);
}

void	open_outfile(char *file_tks, int flags, int *outfd, t_bool *error)
{
	*outfd = open(file_tks, flags, 0644);
	if (*outfd == -1)
		msg_error_open_file(file_tks, error);
}

void	open_files(t_arguments *args, int *ifd, int *ofd, t_commands *cmd)
{	
	int	input_flag;
	int	output_flags;
	int	append_flags;

	input_flag = O_RDONLY;
	output_flags = O_CREAT | O_WRONLY | O_TRUNC;
	append_flags = O_CREAT | O_WRONLY | O_APPEND;
	if (args->id_argv == FILE_IN && cmd->error_file == FALSE)
		open_infile(args->argv, input_flag, ifd, &cmd->error_file);
	if (args->id_argv == FILE_OUT && cmd->error_file == FALSE)
		open_outfile(args->argv, output_flags, ofd, &cmd->error_file);
	if (args->id_argv == FILE_APPEND && cmd->error_file == FALSE)
		open_outfile(args->argv, append_flags, ofd, &cmd->error_file);
	if (args->id_argv == DELIMITER && cmd->error_file == FALSE)
	{
		g_ms.aux_cmd = cmd;
		create_heredoc(args->argv, &cmd->error_file);
	}
}

void	check_redirectors(t_commands *cmd, int id_token)
{	
	if (id_token == FILE_IN)
		cmd->rdc_in = TRUE;
	if (id_token == FILE_OUT && cmd->error_file == FALSE)
		cmd->rdc_out = TRUE;
	if (id_token == FILE_APPEND && cmd->error_file == FALSE)
		cmd->rdc_out_app = TRUE;
	if (id_token == DELIMITER && cmd->error_file == FALSE)
		cmd->rdc_heredoc = TRUE;
}

void	get_files_redirectors(t_commands *cmd, int *ifd, int *ofd)
{
	t_list		*node;
	t_arguments	*args;
	t_arguments	*next;

	node = cmd->argv_list;
	while (node)
	{
		args = (t_arguments *)node->content;
		if (is_metachars(args->id_argv) && args->id_argv != PIPE && \
			node->next)
		{
			next = (t_arguments *)node->next->content;
			check_redirectors(cmd, next->id_argv);
			open_files(next, ifd, ofd, cmd);
		}
		if (args->id_argv == PIPE)
			break ;
		node = node->next;
	}
}
