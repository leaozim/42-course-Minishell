#include "../../include/minishell.h"

int	count_id_token_before_pipe(int id, t_list *node)
{
	t_tokens	*next;
	int			id_count;

	id_count = 0;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	return (id_count);
}

int	count_tokens_before_pipe(void)
{
	t_tokens	*next;
	t_list		*node;
	int			count;

	count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		node = node->next;
		count++;
	}
	return (count);
}

int	count_id_token(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			count;

	count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == id)
			count++;
		node = node->next;
	}
	return (count);
}
