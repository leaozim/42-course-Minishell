#include "../../include/minishell.h"


void deleteNode(t_list **head) 
{
	t_list		*temp;
	t_list		*aux;

	(void)temp;
	(void)aux;
	temp = *head;
	// aux = key->next;
	temp = key->next; 
	ft_lstdelone(key, free);
	
	// printf("")
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
				// deleteNode(&node);
				// deleteNode(&node, next_next->index);
			}
			else
			{
				temp = ft_strjoin(temp, next_next->token);
				free(tklist->token);
				tklist->token = temp;
			}
			i++;
			
		}
		node = node->next;
	}
}
