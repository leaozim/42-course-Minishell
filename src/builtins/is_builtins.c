#include "../../include/minishell.h"

void	is_builtins(void)
{
	t_list		*node;
	t_tokens	*tklist;

	node = ms.tks;
	tklist = (t_tokens *)node->content;
	if (!ft_strcmp("echo", tklist->token))
		echo();
}