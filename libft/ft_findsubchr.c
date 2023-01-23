/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsubchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:57 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/06 15:59:07 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_findsubchr(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			dest = ft_calloc(i + 1, sizeof(char));
			dest = ft_memcpy(dest, str, i);
			return (dest);
		}
		i++;
	}
	return (ft_strdup(str));
}
