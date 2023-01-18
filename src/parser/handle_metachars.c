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

int		consecutive_metachars(char *tkn, char *nxt_tkn, int id, int nxt_id)
{
	if (is_metachars(id))
	{
		if (is_metachars((nxt_id)) && id != PIPE)
		{
			if (id != PIPE)
				msg_error_invalid_synax(nxt_tkn);
			else
				msg_error_invalid_synax(tkn);
			return (1);
		}
		else if (id == PIPE && nxt_id == PIPE)
			return (msg_error_invalid_synax(tkn), 1);
	}
	return (0);
}

int	is_single_metachar(char *token, int id, int len_tokens)
{
	if (is_metachars(id) && len_tokens == 1)
		return (msg_error_invalid_synax(token), 1);
	return (0);
}
