#include "../../include/minishell.h"

void	msg_error_cd(void)
{
	ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
}

int	builtin_cd(void)
{
	char s[100];
	t_tokens	*next;
	t_list		*node;
	char *home;

	node = ms.tks;
	home = getenv("HOME");
	printf("%s\n", getcwd(s, 100));
	if (ms.len_tokens > 2)
		return (msg_error_cd(), 1);
	if (ms.len_tokens == 1)
		chdir(home);
	else if (node->next)
	{
		next = (t_tokens *)node->next->content;
		chdir(next->token);
	}
	printf("%s\n", getcwd(s, 100));
	return (0);
}
