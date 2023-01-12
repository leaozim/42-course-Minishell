#include "../../include/minishell.h"

int get_size_node(t_list *node)
{
	int	size;

	size = 0;
	while(node)
	{
		size++;
		node = node->next;
	}
	return(size);
}

void	msg_error_cd(void)
{
	ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
}

void	msg_result_error(char *token)
{
	char	*msg_error;

	msg_error = ft_strjoin("minishell: cd: ", token);
	perror(msg_error);
	free(msg_error);
}

int	builtin_cd(t_list *cmd_builtins)
{
	char		*home;
	int			result;
	int			size;

	size = 0;
	result = 0;
	home = getenv("HOME");
	
	if (size > 2)
		return (msg_error_cd(), 1);
	if (size == 1)
		result = chdir(home);
	printf(BLUE"cmd builtins = %s\n"RESET, (char *)cmd_builtins->content);
	if (cmd_builtins->next)
		result = chdir((char *)cmd_builtins->next->content);
	if (result < 0)
		msg_result_error(cmd_builtins->next->content);
	return (0);
}
