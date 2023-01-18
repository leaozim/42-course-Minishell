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
	if (!cmd_builtins)
		return (FALSE);
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

void	execute_builtins(t_list *node, int outfd)
{
	t_commands	*cmd;
	char		*arg0;

	cmd = node->content;
	g_ms.size_node_builtin = get_size_node(cmd->builtins_cmd_list);
	arg0 = (char *)cmd->builtins_cmd_list->content;
	if (outfd < 0 && g_ms.num_pipes == 0)
		outfd = STDOUT_FILENO;
	if (!ft_strcmp("cd", arg0))
		(builtin_cd(cmd->builtins_cmd_list));
	else if (!ft_strcmp("echo", arg0))
		(builtin_echo(cmd->builtins_cmd_list, outfd));
	else if (!ft_strcmp("env", arg0))
		(builtin_env(outfd));
	else if (!ft_strcmp("exit", arg0))
		(builtin_exit(cmd->builtins_cmd_list, outfd));
	else if (!ft_strcmp("export", arg0))
		(builtin_export(cmd->builtins_cmd_list, outfd));
	else if (!ft_strcmp("pwd", arg0))
		(builtin_pwd(outfd));
	else if (!ft_strcmp("unset", arg0))
		(builtin_unset(cmd->builtins_cmd_list->next));
	else if (!ft_strcmp("color", arg0))
		bash_change_colors(cmd->builtins_cmd_list);
}
