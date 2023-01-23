/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:50:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Argument list too long\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	is_syntax_quote_error(char *line)
{
	if (!is_valid_quoting(&line))
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Invalid quote syntax\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
