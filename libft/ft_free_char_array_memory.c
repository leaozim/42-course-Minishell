/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array_memory.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:34:20 by etomiyos          #+#    #+#             */
/*   Updated: 2022/12/27 09:34:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_char_array_memory(char **my_array)
{
	int	i;

	i = 0;
	if (my_array == NULL || *my_array == NULL)
		return ;
	while (my_array[i] != NULL)
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}
