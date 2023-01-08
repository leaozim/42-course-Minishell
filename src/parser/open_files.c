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

void	open_files(t_tokens *tks, int *ifd, int *ofd)
{	
	if (tks->id_token == FILE_IN && !tks->err)
		open_infile(tks->token, O_RDONLY, ifd, &tks->err);
	if (tks->id_token == FILE_OUT && !tks->err)
		open_outfile(tks->token, O_CREAT | O_RDWR | O_TRUNC, ofd, &tks->err);
	if (tks->id_token == FILE_APPEND && !tks->err)
		open_outfile(tks->token, O_CREAT | O_RDWR | O_APPEND, ofd, &tks->err);
	if (tks->id_token == DELIMITER && !tks->err)
		creat_heredoc(tks->token, ifd, &tks->err);
}

void	check_open_files(t_list *tks, int *infd, int *outfd)
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
			open_files(next, infd, outfd);
		}
		node = node->next;
	}
}
