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

void	error_invalid_synax(void)
{
	ft_putstr_fd("Invalid syntax\n", STDERR_FILENO);
}

int	consecutive_metachars(int id_tokens, int next_id_tokens)
{
	if (is_metachars(id_tokens))
	{
		if (is_metachars((next_id_tokens)))
		{
			error_invalid_synax();
			return (1);
		}
	}
	return (0);
}

int	is_single_metachar(int id_tokens, int len_tokens)
{
	if (is_metachars(id_tokens) && len_tokens == 1)
	{
		error_invalid_synax();
		return (1);
	}
	return (0);
}
