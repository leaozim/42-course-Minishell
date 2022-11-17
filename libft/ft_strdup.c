/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:16:15 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 16:16:15 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;
	char	*res;
	size_t	leng;

	leng = ft_strlen(str)+1;
	newstr = (char *) ft_calloc(leng, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	res = ft_memmove(newstr, str, leng);
	return (res);
}
