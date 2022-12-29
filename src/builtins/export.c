#include "../../include/minishell.h"
#include "defines.h"
#include <stdlib.h>
#include <unistd.h>

t_bool	check_error_invalid_identifier(char *token)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strchr(token, '=') == NULL)
		while (token[++i])
			if (!ft_isalpha_underscore(token[i]))
				if ((token[0] != '\"') && (token[ft_strlen(token)] != '\"'))
					return (TRUE);
	i = ft_strchr_pos(token, '=');
	if (token[0] == '=')
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

int	print_export(t_list **env)
{
	t_list		*env_node;

	env_node = *env;
	if (ms.len_tokens == 1)
	{
		while (env_node)
		{
			ft_putstr_fd("declare -x "RESET, STDOUT_FILENO);
			ft_putendl_fd((char *)env_node->content, STDOUT_FILENO);
			env_node = env_node->next;
		}
		return (1);
	}
	return (0);
}

int	builtin_export()
{
	t_tokens	*next;
	t_list		*node;

	node = ms.tks;
	if (print_export(&ms.env) == 1)
		return (EXIT_SUCCESS);
	while (node->next)
	{
		next = (t_tokens *)node->next->content;
		if (check_error_invalid_identifier(next->token) == TRUE)
		{
			msg_error_not_a_valid_identifier(next->token, "export");
			return (EXIT_FAILURE);
		}
		ft_lstadd_back(&ms.env, ft_lstnew(ft_strdup(next->token)));
		node = node->next;
	}
	ms.exit_status = 0;
	return (EXIT_SUCCESS);
}
