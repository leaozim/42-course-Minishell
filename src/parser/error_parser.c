#include "../../include/minishell.h"

void	msg_error_invalid_synax(char *token)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	ms.exit = 2;
}

void	msg_error_open_file(char *token, t_bool *error)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	ms.exit = 1;
	*error = TRUE;
}

void	msg_error_heredoc(void)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd("warning: \
				here-document delimited by end-of-file", STDERR_FILENO);
}
