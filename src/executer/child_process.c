#include "../../include/minishell.h"

void	child_process_execution(t_list *node)
{
	char	*path;
	char	**cmds;
	char	**envp;

	path = ((t_commands *)node->content)->path;
	cmds = ((t_commands *)node->content)->cmd_list;
	envp = ((t_commands *)node->content)->envp;
	if (execve(path, cmds, envp) == -1)
	{
		free_cmd_data();
		exit(errno);
	}
}

void	child_process_check(t_list *node)
{
	if (check_path((t_commands *)node->content) == FALSE)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd(((t_commands *)node->content)->cmd_list[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		g_ms.exit_status = COMMAND_NOT_FOUND;
		free_cmd_data();
		exit(g_ms.exit_status);
	}
	close_pipes();
	child_process_execution(node);
}
