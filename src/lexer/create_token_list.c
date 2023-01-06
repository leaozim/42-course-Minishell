#include "../../include/minishell.h"

t_tokens	*create_content(char *tks, int index, int key)
{
	t_tokens	*content;

	content = ft_calloc(1, sizeof(t_tokens));
	content->token = tks;
	content->id_token = index;
	content->index = key;
	return (content);
}

void	create_token_list(char **str, int *id, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_lstadd_back(&g_ms.tks, \
		ft_lstnew(create_content(str[i], id[i], i)));
}
