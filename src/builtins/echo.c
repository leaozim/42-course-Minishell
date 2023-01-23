/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:03 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_operand_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_strlen(str) > 1)
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i])
			return (0);
		else
			return (1);
	}
	return (0);
}

void	increment_the_node_while_there_are_n(t_list **node, int *qtt_n)
{
	char	*next_cmd;

	while (*qtt_n < g_ms.size_node_builtin)
	{
		if ((*node)->next)
		{
			next_cmd = (char *)(*node)->next->content;
			if (is_operand_n(next_cmd))
				*node = (*node)->next;
			else
				break ;
		}
		*qtt_n += 1;
	}
}

int	print_echo_node(t_list **node, t_list *aux, int qtt_n, int fd_out)
{
	char	*next_cmd;
	int		i;
	t_list	*node_cmd;

	i = 0;
	while ((*node)->next)
	{
		next_cmd = (char *)(*node)->next->content;
		if (g_ms.size_node_builtin == 2 && is_operand_n((*node)->next->content))
			return (1);
		ft_putstr_fd(next_cmd, fd_out);
		if (i < g_ms.size_node_builtin - qtt_n - 2)
			ft_putchar_fd(SPACE, fd_out);
		(*node) = (*node)->next;
		i++;
	}
	node_cmd = aux;
	if (node_cmd->next)
	{
		next_cmd = node_cmd->content;
		if (!is_operand_n(next_cmd))
			ft_putchar_fd('\n', fd_out);
	}
	return (0);
}

int	builtin_echo(t_list *cmd_builtins, int fd_out)
{
	int			qtt_n;

	qtt_n = 0;
	if (g_ms.size_node_builtin == 1)
	{
		ft_putchar_fd('\n', fd_out);
		return (g_ms.exit_status = 0, 0);
	}
	increment_the_node_while_there_are_n(&cmd_builtins, &qtt_n);
	if (print_echo_node(&cmd_builtins, cmd_builtins, qtt_n, fd_out))
		return (g_ms.exit_status = 0, 0);
	return (g_ms.exit_status = 0, 0);
}
