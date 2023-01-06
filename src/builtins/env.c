#include "../../include/minishell.h"
#include <unistd.h>

void	builtin_env(void)
{
	t_list	*env_node;

	env_node = g_ms.env;
	while (env_node)
	{
		if (ft_strchr((char *)env_node->content, EQUAL) != NULL)
			ft_putendl_fd((char *)env_node->content, STDOUT_FILENO);
		env_node = env_node->next;
	}
}

void	create_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("i = %d\n", i);
		ft_lstadd_back(&g_ms.env, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
}
