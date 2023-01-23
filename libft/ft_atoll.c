/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:06:45 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/14 12:08:17 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	get_next_positive_digit(long long int result,
							char ch, int *invalid);
static long long int	get_next_negative_digit(long long int result,
							char ch, int *invalid);

long long int	ft_checked_atoll(const char *nptr, int *invalid)
{
	long long int	result;

	result = 0;
	*invalid = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		while (*nptr >= '0' && *nptr <= '9' && *invalid == 0)
			result = (get_next_negative_digit(result, *nptr++, invalid));
		if (*nptr != '\0')
			*invalid = 1;
		return (result);
	}
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *invalid == 0)
		result = (get_next_positive_digit(result, *nptr++, invalid));
	if (*nptr != '\0')
			*invalid = 1;
	return (result);
}

static long long int	get_next_positive_digit(long long int result,
							char ch, int *invalid)
{
	long long int	new_result;

	new_result = 10 * result + (long long int)(ch - '0');
	if (new_result < result)
		*invalid = 1;
	return (new_result);
}

static long long int	get_next_negative_digit(long long int result,
							char ch, int *invalid)
{
	long long int	new_result;

	new_result = 10 * result - (long long int)(ch - '0');
	if (new_result > result)
		*invalid = 1;
	return (new_result);
}
