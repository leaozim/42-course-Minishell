#include "../../include/minishell.h"

t_bool	is_metacharacters(int id_tks)
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

int	are_consecutive_metacharacters(t_tokens *tokens, t_list *no)
{
	if (is_metacharacters(tokens->id_tks))
	{
		if (is_metacharacters(((t_tokens *)no->next->content)->id_tks))
		{
			error_invalid_synax();
			return (1);
		}
	}
	return (0);
}

int	is_single_metacharacter(t_tokens *tokens, int len_tokens)
{
	if (is_metacharacters(tokens->id_tks) && len_tokens == 1)
	{
		error_invalid_synax();
		return (1);
	}
	return (0);
}
