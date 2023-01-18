#include "../../include/minishell.h"

void	builtin_pwd(int outfd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_putendl_fd(pwd, outfd);
	free(pwd);
	return ;
}
