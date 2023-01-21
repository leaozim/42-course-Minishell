#include "../../include/minishell.h"

char	*get_env(char *aux)
{
	t_list	*env_node;
	char	*temp;

	env_node = g_ms.env;
	while (env_node)
	{
		temp = ft_stop_chr((char *)env_node->content, EQUAL);
		if (!ft_strncmp(aux, temp, ft_strlen(aux)))
		{
			free(temp);
			return (ft_strchr((char *)env_node->content, EQUAL) + 1);
		}
		env_node = env_node->next;
		free(temp);
	}
	return (NULL);
}
