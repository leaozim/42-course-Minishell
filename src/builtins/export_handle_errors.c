#include "../../include/minishell.h"

t_bool	check_error_invalid_identifier(char *token)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strchr(token, EQUAL) == NULL)
		while (token[++i])
			if (!ft_isalpha_underscore(token[i]))
				return (TRUE);
	i = ft_strchr_pos(token, EQUAL);
	if (token[0] == EQUAL)
		return (TRUE);
	while (j < i)
	{
		if (!ft_isalpha_underscore(token[0]))
			return (TRUE);
		if (!ft_isalpha_underscore(token[j]) && !ft_isdigit(token[j]))
			return (TRUE);
		j++;
	}
	return (FALSE);
}

void	msg_error_not_a_valid_identifier(char *token, char *cmd)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(" `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	ms.exit_status = 1;
}

t_bool	error_invalid_identifier(t_tokens **next, t_list **node, char *cmd)
{
	if (check_error_invalid_identifier((*next)->token) == TRUE)
	{
		msg_error_not_a_valid_identifier((*next)->token, cmd);
		ms.exit_status = 1;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}
