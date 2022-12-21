#include "../../include/minishell.h"

void	reidentify_some_tokens(t_list *tks)
{
	t_list		*node;
	t_tokens	*tokens;
	t_tokens	*next_tokens;

	node = tks;
	while (node)
	{
		tokens = (t_tokens *)node->content;
		if (is_metachars(tokens->id_token) && tokens->id_token != PIPE && \
			node->next)
		{
			next_tokens = (t_tokens *)node->next->content;
			if (tokens->id_token == HEREDOC)
				next_tokens->id_token = DELIMITER;
			else if (tokens->id_token == APPEND)
				next_tokens->id_token = FILE_APPEND;
			else if (tokens->id_token == RDRCT_IN)
				next_tokens->id_token = FILE_IN;
			else if (tokens->id_token == RDRCT_OU)
				next_tokens->id_token = FILE_OUT;
			else
				next_tokens->id_token = COMMAND;
		}
		node = node->next;
	}
}

int	error_syntaxy_metachars(t_list *tks, int len_tokens)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;

	node = tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (is_single_metachar(tklist->token, tklist->id_token, len_tokens))
			return (1);
		if (node->next)
			next = (t_tokens *)node->next->content;
		if (node->next && consecutive_metachars(tklist->token, next->token, \
			tklist->id_token, next->id_token))
			return (1);
		node = node->next;
	}
	return (0);
}

int	parser(void)
{
	if (error_syntaxy_metachars(ms.tks, ms.len_tokens))
		return (1);
	reidentify_some_tokens(ms.tks);
	check_open_files(ms.tks, &ms.infd, &ms.outfd);
	return (0);
}
