#include "../../include/minishell.h"

t_bool	is_builtins(void)
{
	t_list		*node;
	t_tokens	*tklist;

	node = g_ms.commands;
	tklist = (t_tokens *)node->content;
	if (!ft_strcmp("echo", tklist->token))
		return (builtin_echo(), TRUE);
	else if (!ft_strcmp("cd", tklist->token))
		return (builtin_cd(), TRUE);
	else if (!ft_strcmp("env", tklist->token))
		return (builtin_env(), TRUE);
	if (!ft_strcmp("exit", tklist->token))
		return (builtin_exit(), TRUE);
	else if (!ft_strcmp("export", tklist->token))
		return (builtin_export(), TRUE);
	else if (!ft_strcmp("pwd", tklist->token))
		return (builtin_pwd(), TRUE);
	else if (!ft_strcmp("unset", tklist->token))
		return (builtin_unset(), TRUE);
	else if (!ft_strcmp("color", tklist->token))
		return (bash_change_colors(), TRUE);
	return (FALSE);
}
