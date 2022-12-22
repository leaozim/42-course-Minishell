#include "../../include/minishell.h"

void	env()
{
	t_list	*node;

	node = ms.env;
	while (node)
	{
		printf("%s\n", (char *)node->content);
		node = node->next;
	}
}

void	create_env(char **envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		ft_lstadd_back(&ms.env, ft_lstnew(envp[i]));
		i++;
	}
}