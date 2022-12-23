#include "../../include/minishell.h"
#include "printf_colors.h"

void	msg_error_not_a_valid_identifier(char *token, char *cmd)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(" `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\": not a valid identifier\n", STDERR_FILENO);
	ms.exit_status = 1;
}

int builtin_export(char *token)
{
	int i;

	i = 0;
	if (ft_strchr(token, '=') == NULL)
	{
		while(token[i])
		{
			if (!ft_isalpha_underscore(token[i]))
			{
				msg_error_not_a_valid_identifier(token, "export");
				return(EXIT_FAILURE);
			}
			i++;
		}
		ms.exit_status = 0;
	}
	return (EXIT_SUCCESS);
}