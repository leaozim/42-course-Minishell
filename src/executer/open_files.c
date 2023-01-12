#include "../../include/minishell.h"

void	open_infile(char *file_tks, int flags, int *infd, t_bool *error)
{
	*infd = open(file_tks, flags);
	if (*infd < 0)
		msg_error_open_file(file_tks, error);
}

void	open_outfile(char *file_tks, int flags, int *outfd, t_bool *error)
{
	*outfd = open(file_tks, flags, 0644);
	if (*outfd < 0)
		msg_error_open_file(file_tks, error);
}

void	check_redirectors(t_tokens *tks, int *ifd, int *ofd, t_commands *cmd)
{	
	if (tks->id_token == FILE_IN)
	{
		cmd->rdc_in = TRUE;
		open_infile(tks->token, O_RDONLY, ifd, &cmd->error_file);
	}
	if (tks->id_token == FILE_OUT && cmd->error_file == FALSE)
	{
		cmd->rdc_out = TRUE;
		open_outfile(tks->token, O_CREAT | O_WRONLY | O_TRUNC, ofd, &cmd->error_file);
	}
	if (tks->id_token == FILE_APPEND && cmd->error_file == FALSE)
	{
		cmd->rdc_out_app = TRUE;
		open_outfile(tks->token, O_CREAT | O_WRONLY | O_APPEND, ofd, &cmd->error_file);
	}
	if (tks->id_token == DELIMITER && cmd->error_file == FALSE)
	{
		cmd->rdc_heredoc = TRUE;
		create_heredoc(tks->token, ifd, &cmd->error_file);
	}
}

void	open_files(t_list *tks, t_commands *cmd, int *infd, int *outfd)
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
			check_redirectors(next, infd, outfd, cmd);
		}
		node = node->next;
	}
}
