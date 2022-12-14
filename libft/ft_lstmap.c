/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:52:34 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 15:52:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_list;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			while (first)
			{
				new_list = first -> next;
				(*del)(first -> content);
				free(first);
				first = new_list;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new_list);
		lst = lst -> next;
	}
	return (first);
}
