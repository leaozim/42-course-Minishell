#include "../../include/minishell.h"

void	msg_error_cd(void)
{
	ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
}

void	msg_result_error(char *token)
{
	char	*msg_error;

	msg_error = ft_strjoin("minishell: cd: ", token);
	perror(msg_error);
	free(msg_error);
}

int	builtin_cd(void)
{
	t_tokens	*next;
	t_list		*node;
	char		*home;
	int			result;

	result = 0;
	node = g_ms.tks;
	home = getenv("HOME");
	if (g_ms.len_tokens > 2)
		return (msg_error_cd(), 1);
	if (g_ms.len_tokens == 1)
		result = chdir(home);
	else if (node->next)
	{
		next = (t_tokens *)node->next->content;
		result = chdir(next->token);
	}
	if (result < 0)
		msg_result_error(next->token);
	return (0);
}
