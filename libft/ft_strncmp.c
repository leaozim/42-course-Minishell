/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:23:24 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 16:23:24 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1uc;
	unsigned char	*str2uc;

	str1uc = (unsigned char *) str1;
	str2uc = (unsigned char *) str2;
	i = 0;
	while (i < n && (str1uc[i] || str2uc[i]))
	{
		if (str1uc[i] != str2uc[i])
			return (str1uc[i] - str2uc[i]);
		i++;
	}
	return (0);
}
