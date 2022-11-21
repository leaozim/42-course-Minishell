/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:48:57 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 15:48:57 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	if (*lst != NULL)
	{
		new_list -> next = *lst;
		*lst = new_list;
	}
	*lst = new_list;
}
