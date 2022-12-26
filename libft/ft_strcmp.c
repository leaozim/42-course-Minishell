/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:28:52 by etomiyos          #+#    #+#             */
/*   Updated: 2022/12/26 09:47:15 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				id;

	id = 0;
	while ((s1[id] != '\0') && (s2[id] != '\0') && s1[id] == s2[id])
		id++;
	return ((unsigned char)s1[id] - (unsigned char)s2[id]);
}
