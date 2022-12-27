#include "../../include/minishell.h"


void delete_next_node(t_list **head, t_list **content) 
{
	t_list		*temp;
	t_list		*aux;

	aux = *head;
	temp = (*content)->next;
	ft_lstdelone(*content, free);
	aux->next = temp;
	*head = aux;
}

void delete_next_next_node(t_list **head, t_list **content)
{
	t_list		*temp;
	t_list		*aux;

	aux = *head;
	if ((*content)->next)
	{
		temp = (*content)->next; 
		ft_lstdelone(*content, free);
		aux->next = temp;
		*head = aux;
	}
	else
	{
		(*content)->next = NULL;
		ft_lstdelone(*content, free);
		aux->next = aux;
	}
}

void	join_tokens(t_list **tks)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;
	t_tokens	*next_next;
	char		*temp;
	int			i;

	(void)next;
	node = *tks;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (node->next)
			next = (t_tokens *)node->next->content;
		if (node->next && ft_strchr(next->token, MARKER))
		{
			next_next = (t_tokens *)node->next->next->content;
			if (i == 0)
			{
				temp = ft_strjoin(tklist->token, next_next->token);
				free(tklist->token);
				tklist->token = temp;
				// delete_next_node(&node, &node->next);
				// deleteNode(&node, &node->next->next);
				// deleteNode(&node, next_next->index);
			}
			// else
			// {
			// 	temp = ft_strjoin(temp, next_next->token);
			// 	free(tklist->token);
			// 	tklist->token = temp;
			// 	// delete_next_node(&node, &node->next);
			// }
			i++;
		}
		node = node->next;
	}
}
