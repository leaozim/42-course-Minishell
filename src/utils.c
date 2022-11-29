#include "../include/minishell.h"

void	free_ptrs(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	destroy_minishell(t_minishell ms)
{
	ft_lstclear(&ms.tks, free);
	free(ms.prompt_line);
	free_ptrs(ms.tab_tokens);
	free(ms.tab_id);
}
