#include "../../include/minishell.h"

t_bool	check_unset_chr_valid_name(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!ft_isalpha_underscore(token[0]))
			return (TRUE);
		if (!ft_isalpha_underscore(token[i]) && !ft_isdigit(token[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool check_unset_delete_value(char *token)
{
	t_list	*env_node;
	t_list	*prev;
	char	*content;

	env_node = g_ms.env;
	content = ft_findsubchr((char *)env_node->content, EQUAL);
		if (!ft_strcmp(token, content))
		{
			prev = g_ms.env;
			g_ms.env = g_ms.env->next;
			ft_lstdelone(prev, free);
			free(content);
			return (FALSE);
		}
	free(content);
	while (env_node)
	{
		content = ft_findsubchr((char *)env_node->content, EQUAL);
		if (!ft_strcmp(token, content))
		{
			prev->next = env_node->next;
			ft_lstdelone(env_node, free);
			free(content);
			break ;
		}
		prev = env_node;
		env_node = env_node->next;
		free(content);
	}
	return (FALSE);
}

t_bool	unset_error_identifier(t_tokens **next, t_list **node, char *cmd)
{
	if (check_unset_chr_valid_name((*next)->token) == TRUE)
	{
		msg_error_not_a_valid_identifier((*next)->token, cmd);
		g_ms.exit_status = 1;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}

t_bool unset_delete_value(t_tokens **next, t_list **node)
{
	if (check_unset_delete_value((*next)->token) == TRUE)
	{
		g_ms.exit_status = 0;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}

int	builtin_unset(void)
{
    t_tokens	*next;
	t_list		*node;

    node = g_ms.tks->next;
    while (node)
    {
        next = (t_tokens *)node->content;
        if (unset_error_identifier(&next, &node, "unset") == TRUE)
			continue ;
		if (unset_delete_value(&next, &node) == TRUE)
			continue ;
        node = node->next;
    }
    return (g_ms.exit_status = 0, EXIT_SUCCESS);
}
