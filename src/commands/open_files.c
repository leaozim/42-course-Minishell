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

void	open_files(t_tokens *tks, int *ifd, int *ofd, t_commands *cmd)
{	
	int	input_flag;
	int	output_flags;
	int	append_flags;

	input_flag = O_RDONLY;
	output_flags = O_CREAT | O_WRONLY | O_TRUNC;
	append_flags = O_CREAT | O_WRONLY | O_APPEND;
	if (tks->id_token == FILE_IN)
		open_infile(tks->token, input_flag, ifd, &cmd->error_file);
	if (tks->id_token == FILE_OUT && cmd->error_file == FALSE)
		open_outfile(tks->token, output_flags, ofd, &cmd->error_file);
	if (tks->id_token == FILE_APPEND && cmd->error_file == FALSE)
		open_outfile(tks->token, append_flags, ofd, &cmd->error_file);
	if (tks->id_token == DELIMITER && cmd->error_file == FALSE)
		create_heredoc(tks->token, ifd, &cmd->error_file);
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

void	get_files_redirectors(t_list *tks, t_commands *cmd, int *ifd, int *ofd)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;

	node = tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (is_metachars(tklist->id_token) && tklist->id_token != PIPE && \
			node->next)
		{
			next = (t_tokens *)node->next->content;
			check_redirectors(cmd, next->id_token);
			open_files(next, ifd, ofd, cmd);
		}
		if (tklist->id_token == PIPE)
			break ;
		node = node->next;
	}
}
