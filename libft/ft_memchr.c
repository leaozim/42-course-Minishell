/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:02:58 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 16:02:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*struc;
	unsigned char	charuc;

	struc = (unsigned char *) str;
	charuc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (struc[i] == charuc)
			return (&struc[i]);
		i++;
	}
	return (NULL);
}
