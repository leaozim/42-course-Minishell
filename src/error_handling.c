/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:31:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/17 14:56:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_program_name(int argc)
{
	if (argc > 1)
	{
		printf("Error! Argument list too long\n");
		exit(ARGUMENT_LIST_TOO_LONG);
	}
}
