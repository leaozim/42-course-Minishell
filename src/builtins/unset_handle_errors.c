/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_handle_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:23 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	unset_error_identifier(char **next, t_list **node, char *cmd)
{
	if (check_unset_chr_valid_name(*next) == TRUE)
	{
		msg_error_not_a_valid_identifier(*next, cmd);
		g_ms.exit_status = 1;
		(*node) = (*node)->next;
		return (TRUE);
	}
	return (FALSE);
}
