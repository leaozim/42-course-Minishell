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

// void delete_node(t_list **tlist, int key)
// {
// 	t_list		*node;
// 	t_list		*prev;
// 	t_tokens	*token;
	
// 	node = *tlist;
// 	token = (t_tokens *)node->content;
// 	if (node && token->index == key) 
// 	{
// 		*tlist = node->next;
// 		free(node);
// 		return ;
// 	}
// 	while (node) 
// 	{
// 		token = (t_tokens *)node->content;
// 		if (token->index == key)
// 			break ;
// 		prev = node;
// 		node = node->next;
// 	}
// 	if (node == NULL)
// 		return ;
// 	prev->next = node->next;
// 	free(node);
// }

// // t_list *get_node(t_list **tlist, int key)
// // {
// // 	t_list		*node;
// // 	t_tokens	*token;
// // 	t_list 		*aux;
	
// // 	aux = *tlist;
// // 	(void)aux;
// // 	node = ms.tks;
// // 	token = (t_tokens *)node->content;
// // 	if (node != NULL && token->index == key)
// // 		return (node);
// // 	while (node) 
// // 	{
// // 		printf("key = %d\n", key);
// // 		printf("id  = %d\n", token->index );
// // 		token = (t_tokens *)node->content;

// // 		if (token->index == key)
// // 			return (node);
// // 		node = node->next;
// // 	}
// // 	printf("oi\n");
// // 	if (node == NULL)
// // 		return (node);
// // 	return (NULL);
// // }

// void	print_node(t_list *node)
// {
// 	t_tokens	*tklist;


// 	while (node)
// 	{
// 		printf("aa\n");
// 		tklist = (t_tokens *)node->content;
// 		printf("tokens = %s\n", tklist->token);
// 		// printf("id     = %d\n", tklist->index);
// 		node = node->next;
// 	}
// }

// void	join_tokens(t_list **tks)
// {
// 	t_list		*node;
// 	// t_list		*temp_node;
// 	t_tokens	*tklist;
// 	t_tokens	*next;
// 	t_tokens	*next_next;
// 	// t_tokens	*temp_token;
// 	char		*temp;
// 	// int			marker;
// 	int			i;
// 	char *str;

// 	(void)next;
// 	node = *tks;
// 	// marker = 0;
// 	i = 0;
// 	while (node)
// 	{
// 		tklist = (t_tokens *)node->content;
// 		next = (t_tokens *)node->next->content;
// 		while (node->next && !ft_strchr(next->token, MARKER))
// 		{
// 			node = node->next;
// 			i++;
// 		}
// 		if (node->next)
// 		{
// 			// node = oi next | next_next = casa = oi | casa
// 			next_next = (t_tokens *)node->next->next->content;
// 			temp = ft_strjoin(tklist->token, next_next->token);
// 			free(tklist->token);
// 			tklist->token = temp;
// 			str = tklist->token;
// 			delete_node(&node, i + 1);
// 			delete_node(&node, i + 2);
// 		} // ola | casa | mundo | batata 
// 		else
// 		{

// 			printf("STR = %s\n", str);
// 			printf("AQUI =  %s\n", tklist->token);
// 			temp = ft_strjoin(str, next->token);
// 			// free(str);
// 			free(tklist->token);
// 			tklist->token = temp;
// 			// str = ft_strdup(tklist->token);
// 			// delete_node(&node, i + 1);
// 			// delete_node(&node, i + 2);
// 			printf("size = %d\n", ft_lstsize(node));
// 		}
// 		node = node->next;
// 		i++;
// 	}
// }
	
// oi|ola "oi"6oi oi
// 7
// 5
// echo "oi"6"oi"6"oi" doido
// 7
// 3
// "oi"6"oi"6"oi"
// 5
// 1
//  len = old_len - (2 * qtt_mark)
//

void	join_tokens(char **tks, int len_tokens, char *line)
{
	char	**new_tab;
	int		i;
	int		len_markers;
	char	*temp;
	int		j;
	int		pos;
	char	*aux;

	i = 0;
	j = 0;
	pos = -5;
	len_markers = ft_strchr_count(line, MARKER);
	// if (len_markers == 0)
	// 	return ;
// oi "ola"*"sim"*ok ola | sim
	new_tab = ft_calloc(len_tokens - (2 * len_markers) + 1, sizeof(char*));
	while (tks[i] != NULL)
	{
		if (i + 1 == check_len_tab(tks))
		{
			printf("j = %d\n", j);
			// j++;
			new_tab[j] = tks[i + 1];
			break ;
		}
		if (ft_strchr(tks[i + 1], MARKER))
		{
			if (i == pos)
			{
				aux = ft_strdup(new_tab[j]);
				free(new_tab[j]);
				new_tab[j] = ft_strjoin(aux, tks[i + 2]);
				i += 2;
				j++;
				continue ;
			}
			temp = ft_strjoin(tks[i], tks[i + 2]);
			new_tab[j] = temp;
			pos = i + 2;
			i += 2;
			continue ;
		}
		new_tab[j] = ft_strdup(tks[i]);
		j++;
		i++;
	}
	new_tab[j] = NULL;
	printf("oi\n");
	i = 0;
	while(new_tab[i])
	{
		printf("new tab = %s\n",new_tab[i]);
		i++;
	}
}
