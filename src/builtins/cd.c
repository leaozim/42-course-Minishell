#include "../../include/minishell.h"

void	msg_error_cd(char *token, int error)
{
	ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
	if (error == 1)
		ft_putstr_fd("too many arguments\n", STDERR_FILENO);
	else if (token)
		ft_putstr_fd(token, STDERR_FILENO);
	if (error == 2)
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
}

int	builtin_cd(void)
{
	t_tokens	*next;
	t_list		*node;
	char		*home;
	int			result;

	result = 0;
	node = ms.tks;
	home = getenv("HOME");
	if (ms.len_tokens > 2)
		return (msg_error_cd(NULL, 1), 1);
	if (ms.len_tokens == 1)
		result = chdir(home);
	else if (node->next)
	{
		next = (t_tokens *)node->next->content;
		result = chdir(next->token);
	}
	if (result < 0)
	{
		if (access(next->token, F_OK))
			msg_error_cd(next->token, 2);
		else if (access(next->token, R_OK))
			msg_error_cd(next->token, 3);
	}
	return (0);
}
