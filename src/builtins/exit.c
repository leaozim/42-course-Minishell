#include "../../include/minishell.h"

void	msg_error_exit(int id, char *token)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (id == EXIT_TOO_MANY_ARGC)
	{
		ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd("too many arguments\n", STDERR_FILENO);
		g_ms.exit_status = COMMAND_NOT_FOUND;
	}
	else
	{
		if (id == EXIT_ALONLY)
			g_ms.exit_status = 0;
		else if (id == EXIT_NO_NUMERIC)
		{
			ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd("numeric argument required\n", STDERR_FILENO);
			g_ms.exit_status = 2;
		}
		else if (id == EXIT_NUMERIC)
			g_ms.exit_status = ft_atoi(token);
		destroy_minishell();
		exit(0);
	}
}

void	builtin_exit(t_list *node)
{
	char	*next;

	if (g_ms.size_node_builtin == 1)
		msg_error_exit(EXIT_ALONLY, NULL);
	if (node->next)
	{
		next = (char *)node->next->content;
		if (g_ms.len_tokens >= 2 && !ft_is_num(next))
			msg_error_exit(EXIT_NO_NUMERIC, NULL);
		else if (g_ms.len_tokens == 2 && ft_is_num(next))
			msg_error_exit(EXIT_NUMERIC, next);
		else if (g_ms.len_tokens > 2 && ft_is_num(next))
			msg_error_exit(EXIT_TOO_MANY_ARGC, NULL);
	}
}
