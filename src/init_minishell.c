#include "../include/minishell.h"

void	init_minishell(char	**envp)
{
	ms.tab_tokens = NULL;
	ms.tab_id = NULL;
	ms.tks = NULL;
	ms.env = NULL;
	ms.len_tokens = 0;
	ms.exit_status = 0;
	create_env(envp);
}
