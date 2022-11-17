/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:17:55 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 16:17:55 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	leng;
	char	*newstr;

	leng = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *) ft_calloc(leng, sizeof(char));
	ft_strlcat(newstr, s1, leng);
	ft_strlcat(newstr, s2, leng);
	return (newstr);
}
