#include "../../include/minishell.h"
#include <unistd.h>

void	reidentify_some_tokens(t_list *tks)
{
	t_list		*no;
	t_tokens	*tokens;
	t_tokens	*next_tokens;

	no = tks;
	while (no)
	{
		tokens = (t_tokens *)no->content;
		if (is_metachars(tokens->id_tks) && tokens->id_tks != PIPE && \
			no->next)
		{
			next_tokens = (t_tokens *)no->next->content;
			if (tokens->id_tks == HEREDOC)
				next_tokens->id_tks = DELIMITER;
			else if (tokens->id_tks == APPEND)
				next_tokens->id_tks = FILE_APPEND;
			else if (tokens->id_tks == RDRCT_IN)
				next_tokens->id_tks = FILE_IN;
			else if (tokens->id_tks == RDRCT_OU)
				next_tokens->id_tks = FILE_OUT;
			else
				next_tokens->id_tks = COMMAND;
		}
		no = no->next;
	}
}

int	error_syntaxy_metachars(t_list *tks, int len_tokens)
{
	t_list		*no;
	t_tokens	*tokens;
	t_tokens	*next;

	no = tks;
	while (no)
	{
		tokens = (t_tokens *)no->content;
		if (is_single_metachar(tokens->id_tks, len_tokens))
			return (1);
		if (no->next)
			next = (t_tokens *)no->next->content;
		if (no->next && consecutive_metachars(tokens->id_tks, next->id_tks))
			return (1);
		no = no->next;
	}
	return (0);
}

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

void	open_files(t_tokens *tks, int *infd, int *outfd)
{
	if (tks->id_tks == FILE_IN && !tks->error)
	{
		open_infile(tks->tokens, O_RDONLY , infd, &tks->error);
	}
	if (tks->id_tks == FILE_OUT && !tks->error)
	{
		open_outfile(tks->tokens, O_CREAT | O_RDWR | O_TRUNC, outfd, &tks->error);
	}
	if (tks->id_tks == FILE_APPEND && !tks->error)
	{
		open_outfile(tks->tokens, O_CREAT | O_RDWR | O_APPEND, infd, &tks->error);
	}
	// if (tks->id_tks == DELIMITER)
	// {

	// }
}

void check_open_files(t_list *tks, int *infd, int *outfd)
{
	t_list *no;
	t_tokens	*tokens;
	t_tokens	*next;

	no = tks;
	while (no)
	{
		tokens = (t_tokens *)no->content;
		if (is_metachars(tokens->id_tks) && tokens->id_tks != PIPE && \
			no->next)
		{
			next = (t_tokens *)no->next->content;
			open_files(next, infd, outfd);
		}
		no = no->next;
	}
		
}

int	parser(t_minishell *ms)
{
	if (error_syntaxy_metachars(ms->tks, ms->len_tokens))
		return (1);
	reidentify_some_tokens(ms->tks);
	check_open_files(ms->tks, &ms->infd, &ms->outfd);
	return (0);
}
