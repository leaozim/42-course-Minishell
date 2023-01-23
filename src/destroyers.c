/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:52 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:20:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_ptrs(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_lstdelone_array(t_list **lst)
{
	t_list	*node;

	node = *lst;
	if (!node)
		return ;
	while (node)
	{
		free_ptrs(node->content);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	ft_lstclear_array(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_array(lst);
		*lst = tmp;
	}
}

void	destroy_t_tokens(void *token)
{
	t_tokens	*tklist;

	tklist = (t_tokens *)token;
	free(tklist->token);
	free(tklist);
}

void	destroy_minishell(void)
{
	ft_lstclear(&g_ms.tks, destroy_t_tokens);
	free(g_ms.prompt_line);
	free(g_ms.tab_tokens);
	free(g_ms.tab_id);
}
