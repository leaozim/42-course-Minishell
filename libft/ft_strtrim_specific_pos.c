/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_specific_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 08:45:15 by etomiyos          #+#    #+#             */
/*   Updated: 2022/12/26 12:57:30 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_specific_pos(char *str, int *pos, int term)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	k = ft_strlen(str) - ft_intarray_len(pos, term);
	dest = ft_calloc(k + 1, sizeof(char));
	i = 0;
	j = 0;
	k = 0;
	while (i < (int)ft_strlen(str))
	{
		while (i == pos[k])
		{
			i++;
			k++;
		}
		dest[j] = str[i];
		j++;
		i++;
	}
	return (dest);
}
