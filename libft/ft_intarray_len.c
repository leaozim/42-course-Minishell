/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 08:46:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/12/26 08:47:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intarray_len(int *array, int terminator)
{
	int	i;

	i = 0;
	while (array[i] != terminator)
		i++;
	return (i);
}
