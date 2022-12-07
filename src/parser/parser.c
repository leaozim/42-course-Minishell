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
		if (is_metacharacters(tokens->id_tks) && tokens->id_tks != PIPE && \
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

int	error_syntaxy_metacharacter(t_minishell *ms)
{
	t_list		*no;
	t_tokens	*tokens;

	no = ms->tks;
	while (no)
	{
		tokens = (t_tokens *)no->content;
		if (is_single_metacharacter(tokens, ms->len_tab_tokens))
			return (1);
		if (no->next && are_consecutive_metacharacters(tokens, no))
			return (1);
		no = no->next;
	}
	return (0);
}

int	parser(t_minishell *ms)
{
	if (error_syntaxy_metacharacter(ms))
		return(1);
	reidentify_some_tokens(ms->tks);
	return (0);
}
