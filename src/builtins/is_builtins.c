#include "../../include/minishell.h"

void	is_builtins(void)
{
	t_list		*node;
	t_tokens	*tklist;

	node = ms.tks;
	if (!ms.tks)
		return ;
	tklist = (t_tokens *)node->content;
	if (!ft_strcmp("cd", tklist->token))
		builtin_cd();
	else if (!ft_strcmp("echo", tklist->token))
		builtin_echo();
	else if (!ft_strcmp("env", tklist->token))
		builtin_env();
	if (!ft_strcmp("exit", tklist->token))
		builtin_exit();
	else if (!ft_strcmp("export", tklist->token))
		builtin_export();
	else if (!ft_strcmp("pwd", tklist->token))
		builtin_pwd();
	else if (!ft_strcmp("unset", tklist->token))
		builtin_unset();
	else if (!ft_strcmp("color", tklist->token))
		bash_change_colors();
	else if (!ft_strcmp("clear", tklist->token))
		cmd_clear();
}
