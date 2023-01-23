/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:49 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:50:05 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	msg_available_colors(void)
{
	ft_putstr_fd(MSG_INVALID_COLOR \
	RED"\nred" GREEN"\ngreen" \
	YELLOW"\nyellow" BLUE"\nblue" \
	MAGENTA"\nmagenta" CYAN"\ncyan" \
	RESET"\nreset (default)\n", \
	STDIN_FILENO);
}

void	bash_change_colors(t_list *node)
{
	char	*next;

	while (node->next)
	{
		next = (char *)node->next->content;
		if (!ft_strcmp((char *)next, "red"))
			ft_putstr_fd(RED, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "green"))
			ft_putstr_fd(GREEN, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "blue"))
			ft_putstr_fd(BLUE, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "yellow"))
			ft_putstr_fd(YELLOW, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "magenta"))
			ft_putstr_fd(MAGENTA, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "cyan"))
			ft_putstr_fd(CYAN, STDIN_FILENO);
		else if (!ft_strcmp((char *)next, "reset"))
			ft_putstr_fd(RESET, STDIN_FILENO);
		else
			msg_available_colors();
		node = node->next;
	}
}
