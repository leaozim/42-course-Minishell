/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:34:11 by etomiyos          #+#    #+#             */
/*   Updated: 2022/12/24 14:34:49 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strchr_pos(const char *s, int c)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	return (0);
}