#include "../../include/minishell.h"

void	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return ;
	printf("%s\n", pwd);
	free(pwd);
	return ;
}
