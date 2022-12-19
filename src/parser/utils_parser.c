#include "../../include/minishell.h"

t_bool	is_metachars(int id_tks)
{
	if (id_tks == HEREDOC || \
		id_tks == APPEND || \
		id_tks == RDRCT_IN || \
		id_tks == RDRCT_OU || \
		id_tks == PIPE)
		return (TRUE);
	return (FALSE);
}

int	consecutive_metachars(char *token, int id_tokens, int next_id_tokens)
{
	// t_tokens *last_tokens;

	// (void)token;
	// last_tokens = (t_tokens *)ft_lstlast(ms.tks)->content;
	if (is_metachars(id_tokens))
	{
		if (is_metachars((next_id_tokens)))
		{
			error_invalid_synax(token);
			return (1);
		}
	}
	return (0);
}

int	is_single_metachar(int id_tokens, int len_tokens)
{
	if (is_metachars(id_tokens) && len_tokens == 1)
	{
		error_invalid_synax("newline");
		return (1);
	}
	return (0);
}

void	destroy_heredoc(void)
{
	free_ptrs(ms.tab_tokens);
	ft_lstclear(&ms.tks, free);
	free(ms.tab_id);
	free(ms.line_heredoc);
}
