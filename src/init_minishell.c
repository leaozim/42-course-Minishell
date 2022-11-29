#include "../include/minishell.h"

void	init_minishell(t_minishell *ms)
{
	ms->tab_tokens = NULL;
	ms->tab_id = NULL;
	ms->tks = NULL;
	ms->qtt_tokens = 0;
	// ms->modified_str = ft_calloc(1, sizeof(char));
	
}
