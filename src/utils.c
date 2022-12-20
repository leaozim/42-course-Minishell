#include "../include/minishell.h"

void	free_ptrs(char **str)
{
	int	i;

	i = 0;
	if (!str || !*(str))
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	destroy_t_tokens(void *token)
{
	t_lst_tokens	*tks;

	tks = (t_lst_tokens *)token;
	free(tks->token);
	free(tks);
}

void	destroy_minishell(void)
{
	ft_lstclear(&ms.tks, destroy_t_tokens); //ms.list_tks mudar
	free(ms.prompt_line);
	free(ms.tab_tokens);
	free(ms.tab_id);
}
