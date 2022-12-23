#include "../../include/minishell.h"
#include <stdlib.h>

void	msg_error_not_a_valid_identifier(char *token, char *cmd)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(" `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	ms.exit_status = 1;
}

t_bool	check_error_invalid_identifier(char *token)
{
	int i;
	int	j;

	i = -1;
	j = 0;
	if (ft_strchr(token, '=') == NULL)
		while (token[++i])
			if (!ft_isalpha_underscore(token[i]))
				if ((token[0] != '\"') && (token[ft_strlen(token)] != '\"'))
					return (TRUE);
	i = ft_strrchr_pos(token, '=');
	if (token[0] == '=')
		return (TRUE);
	while(j < i)
	{
		if (!ft_isalpha_underscore(token[0]))
			return (TRUE);
		if (!ft_isalpha_underscore(token[j]) && !ft_isdigit(token[j]))
			return (TRUE);
		j++;
	}
	return (FALSE);
}

int builtin_export(char *token)
{
	if (check_error_invalid_identifier(token) == TRUE)
	{
		msg_error_not_a_valid_identifier(token, "export");
		return(EXIT_FAILURE);
	}
	ms.exit_status = 0;
	// ft_lstadd_back(&ms.env, ft_lstnew(token));
	// t_list *node;

	// node = ms.env;
	// node = ft_lstlast(node);
	// printf(RED"%s\n"RESET, (char *)node->content);
	return (EXIT_SUCCESS);
}