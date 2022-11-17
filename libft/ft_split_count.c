/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:34:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/01 20:10:38 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_count_solo(char const *s, char c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *) s;
	while (*a)
	{
		while (*a == c)
			a++;
		if (!(*a))
			break ;
		while (*a != c && *a != 0)
			a++;
		i++;
	}
	return (i);
}
