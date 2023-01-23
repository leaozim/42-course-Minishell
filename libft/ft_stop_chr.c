/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:18 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/06 15:56:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stop_chr(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			dest = ft_calloc(i + 2, sizeof(char));
			dest = ft_memcpy(dest, str, i + 1);
			return (dest);
		}
		i++;
	}
	return (str);
}
