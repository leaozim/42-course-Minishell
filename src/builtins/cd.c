#include "../../include/minishell.h"

void	msg_error_cd(void)
{
	ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
	g_ms.exit_status = 1;
}

void	msg_result_error(char *token)
{
	char	*msg_error;

	msg_error = ft_strjoin("Minishell: cd: ", token);
	perror(msg_error);
	free(msg_error);
	g_ms.exit_status = 1;
}

int	builtin_cd(t_list *cmd_builtins)
{
	char		*home;
	int			result;

	result = 0;
	home = getenv("HOME");
	if (g_ms.size_node_builtin > 2)
		return (msg_error_cd(), 1);
	if (g_ms.size_node_builtin == 1)
		result = chdir(home);
	if (cmd_builtins->next)
		result = chdir((char *)cmd_builtins->next->content);
	if (result < 0)
		msg_result_error(cmd_builtins->next->content);
	return (0);
}
