#include "../../include/minishell.h"

void	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return ;
}
