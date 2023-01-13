#include "../../include/minishell.h"

t_bool	unset_error_identifier(char **next, t_list **node, char *cmd)
{
	if (check_unset_chr_valid_name(*next) == TRUE)
	{
		msg_error_not_a_valid_identifier(*next, cmd);
		g_ms.exit_status = 1;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}
