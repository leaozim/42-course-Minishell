#include "../../include/minishell.h"


void	delete_next_node(t_list **head, t_list **content) 
{
	t_list		*temp;
	t_list		*aux;

	aux = *head;
	temp = (*content)->next;
	ft_lstdelone(*content, free);
	aux->next = temp;
	*head = aux;
}

void delete_node(t_list ** tlist, int key)
{
	t_list		*node;
	t_list		*prev;
	t_tokens	*token;
	
	node = *tlist;
	token = (t_tokens *)node->content;
	if (node != NULL && token->index == key) {
		*tlist = node->next;
		free(node);
		return;
	}
	while (node) 
	{
		if (token->index == key)
			break ;
		printf("id = %d\n", token->index);
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return;
	prev->next = node->next;
	free(node);
}
 
void	join_tokens(t_list **tks)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;
	t_tokens	*next_next;
	char		*temp;
	int			marker;
	int			i;

	(void)next;
	node = *tks;
	marker = 0;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (node->next)
			next = (t_tokens *)node->next->content;
		if (node->next && ft_strchr(next->token, MARKER))
		{
			next_next = (t_tokens *)node->next->next->content;
			if (marker == 0)
			{
				temp = ft_strjoin(tklist->token, next_next->token);
				free(tklist->token);
				tklist->token = temp; 
				delete_node(&node, i + 1);
				// delete_node(&node, i + 2);
				// delete_next_next_node(&node, &node->next->next);
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
			marker++;
		}
		i++;
		node = node->next;
	}
}
