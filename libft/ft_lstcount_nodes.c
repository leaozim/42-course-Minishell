/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:54:11 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/18 10:10:43 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount_nodes(t_list *lst)
{
	int		count;
	t_list	*env_node;

	count = 0;
	env_node = lst;
	if (!env_node)
		return (count);
	while (env_node != NULL)
	{
		count++;
		env_node = env_node->next;
	}
	return (count);
}
