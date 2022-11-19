/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:31:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/19 17:18:24 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_program(int argc)
{
	if (argc > 1)
	{
		printf("Error! Argument list too long\n");
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}
