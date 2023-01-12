/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:34:35 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/12 14:35:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(char **array)
{
	int i;
	
	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
