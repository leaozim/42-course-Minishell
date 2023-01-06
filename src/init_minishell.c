#include "../include/minishell.h"

void	init_minishell(char	**envp)
{
	g_ms.tab_tokens = NULL;
	g_ms.tab_id = NULL;
	g_ms.tks = NULL;
	g_ms.env = NULL;
	g_ms.len_tokens = 0;
	g_ms.exit_status = 0;
	create_env(envp);
}
