/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:53 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:19:54 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	msg_error_cmd_not_found(int status, char *cmd)
{
	if (status == 127)
	{
		ft_putstr_fd("MiniHELL: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
	}
	else
		strerror(status);
}
