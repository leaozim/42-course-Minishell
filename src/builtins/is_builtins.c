#include "../../include/minishell.h"

int	get_size_node(t_list *node)
{
	int	size;

	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

t_bool	is_builtins(t_list *node)
{
	t_list		*cmd_builtins;
	char		*cmd;

	cmd_builtins = (((t_commands *)node->content)->builtins_cmd_list);
	cmd = cmd_builtins->content;
	if (!ft_strcmp("cd", cmd))
		return (TRUE);
	else if (!ft_strcmp("echo", cmd))
		return (TRUE);
	else if (!ft_strcmp("env", cmd))
		return (TRUE);
	if (!ft_strcmp("exit", cmd))
		return (TRUE);
	else if (!ft_strcmp("export", cmd))
		return (TRUE);
	else if (!ft_strcmp("pwd", cmd))
		return (TRUE);
	else if (!ft_strcmp("unset", cmd))
		return (TRUE);
	else if (!ft_strcmp("color", cmd))
		return (TRUE);
	return (FALSE);
}

void	open_fds(t_list *node)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)node->content)->infd;
	outfd = ((t_commands *)node->content)->outfd;

	if (infd > 0)
		dup2(infd, STDIN_FILENO);
	if (outfd > 0)
		dup2(outfd, STDOUT_FILENO);
}

void	execute_builtins(t_list *node)
{
	t_list		*cmd_builtins;
	char		*cmd;

	cmd_builtins = (((t_commands *)node->content)->builtins_cmd_list);
	g_ms.size_node_builtin = get_size_node(cmd_builtins);
	cmd = (char *)cmd_builtins->content;
	if (!ft_strcmp("cd", cmd))
		(builtin_cd(cmd_builtins));
	else if (!ft_strcmp("echo", cmd))
		(builtin_echo(cmd_builtins));
	else if (!ft_strcmp("env", cmd))
		(builtin_env());
	else if (!ft_strcmp("exit", cmd))
		(builtin_exit(cmd_builtins));
	else if (!ft_strcmp("export", cmd))
		(builtin_export(cmd_builtins));
	else if (!ft_strcmp("pwd", cmd))
		(builtin_pwd());
	else if (!ft_strcmp("unset", cmd))
		(builtin_unset(cmd_builtins->next));
	else if (!ft_strcmp("color", cmd))
		bash_change_colors(cmd_builtins);
	// open_fds(node);
	free_cmd_data();
	// destroy_minishell();
	// ft_lstclear(&g_ms.env, free);
}
