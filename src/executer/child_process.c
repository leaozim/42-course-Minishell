#include "../../include/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	dup_redirection(t_list *node)
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

// void	child_dup_redirection(t_list *node, int i) //refatorar
// {
// 	// int	infd;
// 	// int	rdc_in;
// 	// int	outfd;
// 	// int rdc_out;
// 	// int rdc_out_app;
// 	// int	rdc_heredoc;

// 	// infd = ((t_commands *)node->content)->infd;
// 	// rdc_in = ((t_commands *)node->content)->rdc_in;
// 	// outfd = ((t_commands *)node->content)->outfd;
// 	// rdc_out = ((t_commands *)node->content)->rdc_out;
// 	// rdc_out_app = ((t_commands *)node->content)->rdc_out_app;
// 	// rdc_heredoc = ((t_commands *)node->content)->rdc_heredoc;
 
// 	//ls > 99 | ls > 100

// 	// printf(BLUE"%d\n"RESET, rdc_out);
// 	// if (rdc_out == TRUE)
// 	// 	dup2(outfd, STDOUT_FILENO);
// 	// else if (i != g_ms.num_pipes)
// 	// {
// 	// 	dup2(g_ms.array_fd[i][0], STDIN_FILENO);
// 	// 	dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
// 	// }
	
// 	// else if (g_ms.num_pipes > 0)
// 	// {
// 	// 	if (i == 0)
// 	// 	{
// 	// 		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
// 	// 	}
// 	// 	else if (i != g_ms.num_pipes)
// 	// 	{
// 	// 		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
// 	// 		dup2(g_ms.array_fd[i][1], STDOUT_FILENO);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		dup2(g_ms.array_fd[i - 1][0], STDIN_FILENO);
// 	// 	}
// 	// }
// }

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
	if (i)
		printf(" ");
	// child_dup_redirection(node, i);
	close_pipes();
	child_process_execution(node);
}
