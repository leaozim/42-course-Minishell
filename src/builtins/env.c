#include "../../include/minishell.h"

void	builtin_env(void)
{
	t_list	*node;
	int		i;

	node = ms.env;
	i = 0;
	while (node)
	{
		printf(GREEN"%d)"RESET "%s\n", i, (char *)node->content);
		node = node->next;
		i++;
	}
}

void	create_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&ms.env, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
}
