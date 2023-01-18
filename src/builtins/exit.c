#include "../../include/minishell.h"

void	exit_allony(void)
{
	destroy_minishell();
	exit(EXIT_SUCCESS);
}

void	exit_no_numeric(void)
{
	ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd("numeric argument required\n", STDERR_FILENO);
	destroy_minishell();
	exit(2);
}

void	exit_numeric(char *token, int invalid)
{
	long long int	code;

	code = ft_checked_atoll(token, &invalid);
	destroy_minishell();
	g_ms.exit_status = code % 256LL;
	exit((g_ms.exit_status));
}

void	msg_error_exit(int id, char *token)
{
	int	invalid;

	invalid = 0;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (id == EXIT_TOO_MANY_ARGC)
	{
		ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd("too many arguments\n", STDERR_FILENO);
		destroy_minishell();
		exit(EXIT_FAILURE);
	}
	else
	{
		if (id == EXIT_ALONLY)
			exit_allony();
		else if (id == EXIT_NO_NUMERIC)
			exit_no_numeric();
		else if (id == EXIT_NUMERIC)
			exit_numeric(token, invalid);
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
		if (g_ms.size_node_builtin >= 2 && \
			(!ft_is_num(next) || ft_islong_long(next) == 0))
			msg_error_exit(EXIT_NO_NUMERIC, NULL);
		else if (g_ms.size_node_builtin == 2 && ft_is_num(next))
			msg_error_exit(EXIT_NUMERIC, next);
		else if (g_ms.size_node_builtin > 2 && ft_is_num(next))
			msg_error_exit(EXIT_TOO_MANY_ARGC, NULL);
	}
}
