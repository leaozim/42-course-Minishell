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
	if (!ft_strcmp("pwd", tklist->token))
		builtin_pwd();
	if (!ft_strcmp("cd", tklist->token))
		builtin_cd();
	if (!ft_strcmp("exit", tklist->token))
		builtin_exit();
	if (!ft_strcmp("env", tklist->token))
		builtin_env();
	// if (!ft_strcmp("export", tklist->token))
	// 	builtin_export();
}
