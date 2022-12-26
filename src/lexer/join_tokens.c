#include "../../include/minishell.h"


// void	join_tokens(t_list **tks)
// {
// 	t_list		*node;
// 	t_list		*new_node;
// 	t_tokens	*tklist;
// 	t_tokens	*next;
// 	t_tokens	*next_next;
// 	char		*temp;
// 	int			i;
// 	char 		*aux;

// 	(void)next;
// 	node = *tks;
// 	i = 0;
// 	while (node)
// 	{
// 		tklist = (t_tokens *)node->content;
// 		if (node->next)
// 			next = (t_tokens *)node->next->content;
// 		if (ft_strchr(next->token, MARKER))
// 		{
// 			next_next = (t_tokens *)node->next->next->content;
// 			if (i == 0)
// 			{
// 				temp = ft_strjoin(tklist->token, next_next->token);
// 				free(tklist->token);
// 				tklist->token = temp;
// 			}
// 			else
// 			{
// 				temp = ft_strjoin(temp, next_next->token);
// 				free(tklist->token);
// 				tklist->token = temp;
// 			}
			
// 		}
// 		i++;
// 		node = node->next;
// 	}
// }
