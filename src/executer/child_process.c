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
	// int	rdc_out;
	// int	rdc_in;

	infd = ((t_commands *)node->content)->infd;
	outfd = ((t_commands *)node->content)->outfd;

	// rdc_out = ((t_commands *)node->content)->rdc_out;
	// rdc_in = ((t_commands *)node->content)->rdc_in;

	// int fd1;
	// (void)i;
	// fd1 = open("2", O_CREAT | O_WRONLY | O_APPEND, 0644);

	// dup2(fd1, STDOUT_FILENO);
	// printf("\n");

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

	if (infd > 2)
		dup2(infd, STDIN_FILENO);
	if (outfd > 2)
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

