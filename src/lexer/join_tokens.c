#include "../../include/minishell.h"

void	join_tokens(void)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;
	t_tokens	*next_next;
	char		*temp;


	(void)next;
	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (node->next)
			next = (t_tokens *)node->next->content;
		if (node->next && ft_strchr(next->token, MARKER))
		{
			next_next = (t_tokens *)node->next->next->content;
			temp = ft_strjoin(tklist->token, next_next->token);
			free(tklist->token);
			tklist->token = temp; 
		}
		node = node->next;
	}

}
