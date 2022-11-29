#include "../../include/minishell.h"

t_tokens	*creat_content(char *tks, int index)
{
	t_tokens	*content;

	content = ft_calloc(1, sizeof(t_tokens));
	content->tokens = tks;
	content->id_tks = index;
	return (content);
}

void	create_token_list(t_minishell *ms, char **str, int *id, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_lstadd_back(&ms->tks, \
		ft_lstnew(creat_content(str[i], id[i])));
}