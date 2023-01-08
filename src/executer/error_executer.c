#include "../../include/minishell.h"

void	msg_error_cmd_not_found(int status, char *cmd)
{
	if (status == 127)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
	}
	else
		strerror(status);
}
