#include "../../include/minishell.h"

void	open_infile(char *file_tks, int flags, int *infd, t_bool *error)
{
	*infd = open(file_tks, flags);

	if (*infd == -1)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		*error = TRUE;
	}
}

void	open_outfile(char *file_tks, int flags, int *outfd, t_bool *error)
{
	*outfd = open(file_tks, flags, 0664);
	if (*outfd == -1)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		*error = TRUE;
	}
}

void	open_files(t_lst_tokens *tks, int *ifd, int *ofd)
{	
	if (tks->id_token == FILE_IN && !tks->err)
	{
		open_infile(tks->token, O_RDONLY, ifd, &tks->err);
	}
	if (tks->id_token == FILE_OUT && !tks->err)
	{
		open_outfile(tks->token, O_CREAT | O_RDWR | O_TRUNC, ofd, &tks->err);
	}
	if (tks->id_token == FILE_APPEND && !tks->err)
	{
		open_outfile(tks->token, O_CREAT | O_RDWR | O_APPEND, ofd, &tks->err);
	}
	if (tks->id_token == DELIMITER && !tks->err)
	{
		creat_heredoc(tks->token, ifd, &tks->err);
	}
}

void	check_open_files(t_list *tks, int *infd, int *outfd)
{
	t_list			*no;
	t_lst_tokens	*tokens;
	t_lst_tokens	*next;

	no = tks;
	while (no)
	{
		tokens = (t_lst_tokens *)no->content;
		if (is_metachars(tokens->id_token) && tokens->id_token != PIPE && \
			no->next)
		{
			next = (t_lst_tokens *)no->next->content;
			open_files(next, infd, outfd);
		}
		no = no->next;
	}
}
