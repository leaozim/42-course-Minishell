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

t_bool	unset_delite_first_node(char *token, char *content)
{
	t_list	*prev;

	if (!ft_strcmp(token, content))
	{
		prev = g_ms.env;
		g_ms.env = g_ms.env->next;
		ft_lstdelone(prev, free);
		free(content);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_unset_delete_value(char *token)
{
	t_list	*env_node;
	t_list	*prev;
	char	*content;

	env_node = g_ms.env;
	content = ft_findsubchr((char *)env_node->content, EQUAL);
	if (unset_delite_first_node(token, content) == FALSE)
		return (FALSE);
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

t_bool	unset_delete_value(char **next, t_list **node)
{
	if (check_unset_delete_value(*next) == TRUE)
	{
		g_ms.exit_status = 0;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}

int	builtin_unset(t_list *node)
{
	char	*next;

	while (node)
	{
		next = (char *)node->content;
		if (unset_error_identifier(&next, &node, "unset") == TRUE)
			continue ;
		if (unset_delete_value(&next, &node) == TRUE)
			continue ;
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
