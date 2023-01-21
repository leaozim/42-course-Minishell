#include "../../include/minishell.h"

void	destroy_heredoc(t_commands *cmd)
{
	ft_lstclear(&g_ms.tks, destroy_t_tokens);
	free(g_ms.tab_tokens);
	close(g_ms.fd_heredoc);
	free(g_ms.tab_id);
	ft_lstclear(&g_ms.env, free);

	ft_free_int_array(g_ms.array_fd, g_ms.num_pipes);
	free(g_ms.pid_fd);
	free(cmd->cmd_list);
	// free_ptrs(cmd->cmd_list);
	free(cmd->path);
	free(cmd->envp);
	free(cmd->argv);
	free(cmd->id);
	free_ptrs(cmd->envp_path);
	ft_lstclear(&cmd->builtins_cmd_list, NULL);
	ft_lstclear(&cmd->argv_list, free);
	free(cmd);
	// free_cmd_data();
	// g_ms.exit_status = 0;
}

int	open_heredoc_file(t_bool *error)
{
	int	fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		msg_error_open_file(TMP_FILE, error);
	return (fd);
}

void	write_heredoc_file(char *delimiter)
{
	signal(SIGINT, signal_break_heredoc);
	while (TRUE)
	{
		g_ms.line_heredoc = readline("> ");
		if (!g_ms.line_heredoc)
		{
			free(g_ms.line_heredoc);
			destroy_heredoc(g_ms.aux_cmd);
			msg_error_heredoc();
			close(g_ms.fd_heredoc);
			exit(0);
		}
		if (!ft_strcmp(g_ms.line_heredoc, delimiter))
		{
			free(g_ms.line_heredoc);
			close(g_ms.fd_heredoc);
			destroy_heredoc(g_ms.aux_cmd);
			break ;
		}
		if (g_ms.sig == SIGINT)
		{
			destroy_heredoc(g_ms.aux_cmd);
			g_ms.exit_status = 130;
			exit(g_ms.exit_status);
		}
		ft_putendl_fd(g_ms.line_heredoc, g_ms.fd_heredoc);
		free(g_ms.line_heredoc);
	}
	exit (0);
}

void	create_heredoc(char *delimiter, t_bool *error)
{
	int	pid;
	int	status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
	if (pid == 0)
	{
		g_ms.fd_heredoc = open_heredoc_file(error);
		if (g_ms.fd_heredoc == -1)
			return ;
		write_heredoc_file(delimiter);
	}
	waitpid(pid, &status, 0);
	WIFEXITED(status);
	g_ms.exit_status = WEXITSTATUS(status);
	unlink(TMP_FILE);
}
