/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:53:50 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 17:52:36 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_num(char *nbr)
{
	int	len;

	len = ft_strlen(nbr);
	if (nbr[len - 1] == '.')
		return (0);
	while (*nbr)
	{
		if (ft_isalpha(*nbr))
			return (0);
		nbr++;
	}
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	if (*nbr == '.')
		return (0);
	while (ft_isdigit(*nbr))
		nbr++;
	if (!(*nbr))
		return (1);
	nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		return (0);
	return (1);
}
