#include "../include/minishell.h"

void	init_minishell(t_minishell *ms)
{
	ms->tab_tokens = NULL;
	ms->tab_id = NULL;
	ms->tks = NULL;
	ms->len_tokens = 0;
}
