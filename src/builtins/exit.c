/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:09 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	destroy_exit(int exit_code)
{
	destroy_minishell();
	free_cmd_data();
	ft_lstclear(&g_ms.env, free);
	exit(exit_code);
}

void	msg_error_exit(char *msg, int exit_code)
{
	ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	destroy_exit(exit_code);
	exit(exit_code);
}

void	exit_check_error(int id, char *token, int outfd)
{
	long long int	code;
	int				invalid;

	invalid = 0;
	ft_putstr_fd("exit\n", outfd);
	if (id == EXIT_TOO_MANY_ARGC)
		msg_error_exit("too many arguments", EXIT_FAILURE);
	else
	{
		if (id == EXIT_ALONLY)
		{
			destroy_exit(EXIT_SUCCESS);
			exit(EXIT_SUCCESS);
		}
		else if (id == EXIT_NO_NUMERIC)
			msg_error_exit("numeric argument required", 2);
		else if (id == EXIT_NUMERIC)
		{
			code = ft_checked_atoll(token, &invalid);
			g_ms.exit_status = code % 256LL;
			destroy_exit(g_ms.exit_status);
			exit(g_ms.exit_status);
		}
	}
}

int	ft_islong_long(char *str)
{
	long long	out;
	int			c;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	out = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		c = *str - '0';
		if (out > (9223372036854775807 - c) / 10)
			return (0);
		out = out * 10 + c;
		str++;
	}
	return (1);
}

void	builtin_exit(t_list *node, int outfd)
{
	char	*next;

	if (g_ms.size_node_builtin == 1)
		exit_check_error(EXIT_ALONLY, NULL, outfd);
	if (node->next)
	{
		next = (char *)node->next->content;
		if (g_ms.size_node_builtin >= 2 && \
			(!ft_is_num(next) || ft_islong_long(next) == 0))
			exit_check_error(EXIT_NO_NUMERIC, NULL, outfd);
		else if (g_ms.size_node_builtin == 2 && ft_is_num(next))
			exit_check_error(EXIT_NUMERIC, next, outfd);
		else if (g_ms.size_node_builtin > 2 && ft_is_num(next))
			exit_check_error(EXIT_TOO_MANY_ARGC, NULL, outfd);
	}
}
