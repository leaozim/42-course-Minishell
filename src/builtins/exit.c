#include "../../include/minishell.h"

void	msg_error_exit(int id, char *token, int outfd)
{
	long long int	code;
	int		invalid;

	invalid = 0;
	ft_putstr_fd("exit\n", outfd);
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
		{
			destroy_minishell();
			exit(EXIT_SUCCESS);
		}
		else if (id == EXIT_NO_NUMERIC)
		{
			ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd("numeric argument required\n", STDERR_FILENO);
			destroy_minishell();
			exit(2);
		}
		else if (id == EXIT_NUMERIC)
		{
			code = ft_checked_atoll(token, &invalid);
			destroy_minishell();
			g_ms.exit_status = code % 256LL;
			exit((g_ms.exit_status));
		}
	}
}

int    ft_islong_long(char *str)
{
    long long    out;
    int            c;

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
		msg_error_exit(EXIT_ALONLY, NULL, outfd);
	if (node->next)
	{
		next = (char *)node->next->content;
		if (g_ms.size_node_builtin >= 2 &&
			(!ft_is_num(next) || ft_islong_long(next) == 0))
			msg_error_exit(EXIT_NO_NUMERIC, NULL, outfd);
		else if (g_ms.size_node_builtin == 2 && ft_is_num(next))
			msg_error_exit(EXIT_NUMERIC, next, outfd);
		else if (g_ms.size_node_builtin > 2 && ft_is_num(next))
			msg_error_exit(EXIT_TOO_MANY_ARGC, NULL, outfd);
	}
}
