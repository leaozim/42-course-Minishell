#include "../../include/minishell.h"

void	is_builtins(void)
{
	t_list		*node;
	t_tokens	*tklist;

	if (!ms.tks)
		return ;
	node = ms.tks;
	tklist = (t_tokens *)node->content;
	if (!ft_strcmp("echo", tklist->token))
		builtin_echo();
	else if (!ft_strcmp("pwd", tklist->token))
		builtin_pwd();
	else if (!ft_strcmp("cd", tklist->token))
		builtin_cd();
	else if (!ft_strcmp("export", tklist->token))
		builtin_export();
	else if (!ft_strcmp("color", tklist->token))
		bash_change_colors();
}
