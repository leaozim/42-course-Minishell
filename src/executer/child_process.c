#include "../../include/minishell.h"
#include <stdio.h>
#include <unistd.h>

// void	dup_redirection(t_list *node)
// {

// 	printf("qualquer coisa\n");
// }

void	child_dup_redirection(t_list *node, int i)
{
	int	infd;
	int	outfd;

	infd = ((t_commands *)node->content)->infd;
	outfd = ((t_commands *)node->content)->outfd;
	if (i == 0)
	{
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	} 
	else if (i != g_ms.num_pipes)
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
	}
	else
	{
		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
	}
	if (infd > 0)
		dup2(infd, STDIN_FILENO);
	if (outfd > 0)
		dup2(outfd, STDOUT_FILENO);
}

void	child_process_check(t_list *node, int i)
{
	if (check_path((t_commands *)node->content) == FALSE)
	{
		g_ms.exit_status = COMMAND_NOT_FOUND;
		ft_lstclear(&g_ms.env, free);
		free_cmd_data();
		destroy_minishell();
		exit(g_ms.exit_status);
	}
	child_dup_redirection(node, i);
	close_pipes();
	child_process_execution(node);
}

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

