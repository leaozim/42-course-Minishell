#include "../../include/minishell.h"
#include <stdio.h>
// #include <stdio.h>


// void	delete_next_node(t_list **head, t_list **content) 
// {
// 	t_list		*temp;
// 	t_list		*aux;

// 	aux = *head;
// 	temp = (*content)->next;
// 	ft_lstdelone(*content, free);
// 	aux->next = temp;
// 	*head = aux;
// }

void delete_node(t_list **tlist, int key)
{
	t_list		*node;
	t_list		*prev;
	t_tokens	*token;
	
	node = *tlist;
	token = (t_tokens *)node->content;
	// if (node && token->index == key) 
	// {
	// 	*tlist = node->next;
	// 	free(node);
	// 	return ;
	// }

	while (node) 
	{
		token = (t_tokens *)node->content;
		if (token->index == key)
			break ;
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return ;
	prev->next = node->next;
	destroy_t_tokens(node->content);
	// free(node->content);
	free(node); 
}


void	join_tokens(t_list **tks)
{
	t_list		*node;
	t_tokens	*tklist;
	t_tokens	*next;
	t_tokens	*next_next;
	char		*temp;

	node = *tks;
	tklist = (t_tokens *)node->content;
	if (!node->next)
		return ;
	next = (t_tokens *)node->next->content;
	while (node && !ft_strchr(next->token, MARKER))
		node = node->next;
	if (node == NULL)
		return ;
	next_next = (t_tokens *)node->next->next->content;
	temp = ft_strjoin(tklist->token, next_next->token);
	free(tklist->token);
	tklist->token = ft_strdup(temp);
	free(temp);
	delete_node(&node, next->index);
	delete_node(&node, next_next->index);
	join_tokens(&ms.tks);
}
