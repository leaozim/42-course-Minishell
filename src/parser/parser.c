#include "../../include/minishell.h"

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

int	parser(t_minishell *ms)
{
	if (error_syntaxy_metachars(ms->tks, ms->len_tokens))
		return (1);
	reidentify_some_tokens(ms->tks);
	check_open_files(ms->tks, &ms->infd, &ms->outfd);
	return (0);
}
