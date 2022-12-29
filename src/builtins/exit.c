#include "../../include/minishell.h"

void	msg_error_exit(int id, char *token)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (id == EXIT_TOO_MANY_ARGC)
	{
		ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd("too many arguments\n", STDERR_FILENO);
		ms.exit_status = COMMAND_NOT_FOUND;
	}
	else
	{
		if (id == EXIT_ALONLY)
			ms.exit_status = 0;
		else if (id == EXIT_NO_NUMERIC)
		{
			ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd("numeric argument required\n", STDERR_FILENO);
			ms.exit_status = 2;
		}
		else if (id == EXIT_NUMERIC)
			ms.exit_status = ft_atoi(token);
		destroy_minishell();
		exit(0);
	}
}

void	builtin_exit(void)
{
	t_tokens	*next;
	t_list		*node;

	node = ms.tks;
	if (ms.len_tokens == 1)
		msg_error_exit(EXIT_ALONLY, NULL);
	if (node->next)
	{
		next = (t_tokens *)node->next->content;
		if (ms.len_tokens >= 2 && !ft_is_num(next->token))
			msg_error_exit(EXIT_NO_NUMERIC, NULL);
		else if (ms.len_tokens == 2 && ft_is_num(next->token))
			msg_error_exit(EXIT_NUMERIC, next->token);
		else if (ms.len_tokens > 2 && ft_is_num(next->token))
			msg_error_exit(EXIT_TOO_MANY_ARGC, NULL);
	}
}
