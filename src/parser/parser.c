#include "../../include/minishell.h"

void	reidentify_some_tokens(t_list *tks)
{
	t_list			*no;
	t_lst_tokens	*tokens;
	t_lst_tokens	*next_tokens;

	no = tks;
	while (no)
	{
		tokens = (t_lst_tokens *)no->content;
		if (is_metachars(tokens->id_token) && tokens->id_token != PIPE && \
			no->next)
		{
			next_tokens = (t_lst_tokens *)no->next->content;
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
		no = no->next;
	}
}

int	error_syntaxy_metachars(t_list *tks, int len_tokens)
{
	t_list			*no;
	t_lst_tokens	*tokens;
	t_lst_tokens	*next;

	no = tks;
	while (no)
	{
		tokens = (t_lst_tokens *)no->content;
		if (is_single_metachar(tokens->id_token, len_tokens))
			return (1);
		if (no->next)
			next = (t_lst_tokens *)no->next->content;
		if (no->next && consecutive_metachars(tokens->id_token, next->id_token))
			return (1);
		no = no->next;
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



// int	expander_tokens(t_list **tks)
// {
// 	t_list		*no;
// 	t_tokens	*tokens;
// 	t_tokens	*next;

// 	no = tks;
// 	while (no)
// 	{
// 		tokens = (t_tokens *)no->content;
// 		if (is_single_metachar(tokens->id_tks, len_tokens))
// 			return (1);
// 		if (no->next)
// 			next = (t_tokens *)no->next->content;
// 		if (no->next && consecutive_metachars(tokens->id_tks, next->id_tks))
// 			return (1);
// 		no = no->next;
// 	}
// 	return (0);
// }
