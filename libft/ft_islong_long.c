/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:08:59 by lade-lim          #+#    #+#             */
/*   Updated: 2023/01/18 10:09:06 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islong_long(char *str)
{
	long long	out;
	int			c;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	out = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		c = *str - '0';
		if (out > (9223372036854775807 - c) / 10)
			return (0);
		out = out * 10 + c;
		str++;
	}
	return (1);
}
