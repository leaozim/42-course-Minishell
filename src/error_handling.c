/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:55 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:20:56 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
