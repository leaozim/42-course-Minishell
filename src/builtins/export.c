#include "../../include/minishell.h"
#include <unistd.h>

t_bool	check_error_invalid_identifier(char *token)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strchr(token, EQUAL) == NULL)
		while (token[++i])
			if (!ft_isalpha_underscore(token[i]))
				if ((token[0] != DQUOTES) && (token[ft_strlen(token)] != DQUOTES))
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

void	msg_print_export(t_list **env_node)
{
	char	*aux;

	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	if (ft_strchr((char *)(*env_node)->content, EQUAL) != NULL)
	{	
		aux = ft_stop_chr((char *)(*env_node)->content, EQUAL);
		ft_putstr_fd(aux, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
		ft_putstr_fd(ft_strchr((char *)(*env_node)->content, EQUAL) + 1, STDOUT_FILENO);
		ft_putendl_fd("\"", STDOUT_FILENO);
		free(aux);
	}
	else
		ft_putendl_fd((char *)(*env_node)->content, STDOUT_FILENO);
}

int	print_export(t_list **env)
{
	t_list	*env_node;

	env_node = *env;
	if (ms.len_tokens == 1)
	{
		while (env_node)
		{
			msg_print_export(&env_node);
			env_node = env_node->next;
		}
		return (1);
	}
	return (0);
}

t_bool	check_export_update_value(char *token)
{
	t_list	*env_node;
	int		index;

	env_node = ms.env;
	index = ft_strchr_pos(token, EQUAL);
	while (env_node)
	{
		if (index > 0 && !ft_strncmp((char *)env_node->content, token, index - 1))
		{
			free(env_node->content);
			env_node->content = ft_strdup(token);
			return (TRUE);
		}
		else if (!ft_strncmp((char *)env_node->content, token, ft_strlen(token)))
			return (TRUE);
		env_node = env_node->next;
	}
	return (FALSE);
}

t_bool error_invalid_identifier(t_tokens **next, t_list **node, char *cmd)
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

t_bool	export_update_value(t_tokens **next, t_list **node)
{
	if (check_export_update_value((*next)->token) == TRUE)
	{
		ms.exit_status = 0;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}
//exemplo: export oi oi= oi 7=sim ola=% oi ola= cavalinho %=invalid

int	builtin_export(void)
{
	t_tokens	*next;
	t_list		*node;

	node = ms.tks;
	if (print_export(&ms.env) == 1)
		return (ms.exit_status = 0, EXIT_SUCCESS);
	while (node->next)
	{
		next = (t_tokens *)node->next->content;
		if (error_invalid_identifier(&next, &node, "export") == TRUE)
			continue ;
		if (export_update_value(&next, &node) == TRUE)
			continue ;
		ft_lstadd_back(&ms.env, ft_lstnew(ft_strdup(next->token)));
		node = node->next;
	}
	return (ms.exit_status = 0, EXIT_SUCCESS);
}
