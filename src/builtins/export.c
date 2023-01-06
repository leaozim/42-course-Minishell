#include "../../include/minishell.h"

void	msg_print_export(t_list **env_node)
{
	char	*aux;
	char	*str;

	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	str = (char *)(*env_node)->content;
	if (ft_strchr(str, EQUAL) != NULL)
	{	
		aux = ft_stop_chr(str, EQUAL);
		ft_putstr_fd(aux, STDOUT_FILENO);
		ft_putchar_fd(DQUOTES, STDOUT_FILENO);
		ft_putstr_fd(ft_strchr(str, EQUAL) + 1, STDOUT_FILENO);
		ft_putchar_fd(DQUOTES, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
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
		printf(GREEN"env = %s\n"RESET, (char*)env_node->content);
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
	char	*name;
	char	*content;

	env_node = ms.env;
	name = ft_findsubchr(token, EQUAL);
	while (env_node)
	{
		content = ft_findsubchr((char *)env_node->content, EQUAL);
		if (!ft_strcmp(name, content))
		{
			if (ft_strchr(token, EQUAL) != NULL)
				ft_strupdate((char **)&env_node->content, ft_strdup(token));
			return (free(content), free(name), TRUE);
		}
		free(content);
		env_node = env_node->next;
	}
	return (free(name), FALSE);
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
