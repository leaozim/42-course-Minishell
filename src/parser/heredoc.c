#include "../../include/minishell.h"
#include <signal.h>
#include <stdio.h>

void	safe_free(void **content)
{
	if (!*content)
		return ;
	free(*content);
	*content = NULL;
}

void	destroy_ctrl_c(void)
{

	dprintf(2, "********************************\n");
	ft_lstclear(&g_ms.cmd->argv_list, NULL);
	ft_lstclear(&g_ms.free_me, free);
	ft_lstclear(&g_ms.tks, destroy_t_tokens);
	free(g_ms.tab_tokens);
	free(g_ms.pid_fd);
	ft_free_int_array(g_ms.array_fd, g_ms.num_pipes);
	free(g_ms.tab_id);
	ft_lstclear(&g_ms.env, free);

}
// void	destroy_heredoc(t_commands *cmd)
// {
// 	ft_lstclear(&g_ms.cmd->argv_list, NULL);
// 	ft_lstclear(&g_ms.free_me, free);
// 	ft_lstclear(&g_ms.tks, destroy_t_tokens);
// 	free(g_ms.tab_tokens);
// 	free(g_ms.pid_fd);
// 	ft_free_int_array(g_ms.array_fd, g_ms.num_pipes);
// 	free(g_ms.tab_id);
// 	ft_lstclear(&g_ms.env, free);
// 	g_ms.exit_status = 0;
// }

void	break_heredoc(int fd, int fd_file_temp)
{
	close(fd);
	close (fd_file_temp);
	unlink(TMP_FILE);
	g_ms.exit_status = 130;
}

int	open_heredoc_file(t_bool *error)
{
	int	fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		msg_error_open_file(TMP_FILE, error);
	return (fd);
}

void	write_heredoc_file(char *delimiter, int *fd, t_commands *cmd)
{
	dprintf(2, "o******************************************************o\n");
	signal(SIGINT, signal_break_heredoc);
	(void)cmd;
	while (TRUE)
	{
		g_ms.line_heredoc = readline("> ");
		if (!g_ms.line_heredoc)
		{
			free(g_ms.line_heredoc);
			destroy_ctrl_c();
			msg_error_heredoc();
			close(*fd);
			exit(0);
		}
		if (!ft_strcmp(g_ms.line_heredoc, delimiter))
		{
			free(g_ms.line_heredoc);
			close(*fd);
			destroy_ctrl_c();
			break ;
		}
		ft_putendl_fd(g_ms.line_heredoc, *fd);
		free(g_ms.line_heredoc);
	}
	close(g_ms.fd_heredoc);
	exit (0);
}

void	create_heredoc(char *delimiter, int *fd, t_bool *error, t_commands *cmd)
{
	int	pid;
	int	status;
	int	fd_file_temp;

	signal(SIGINT, SIG_IGN);
	fd_file_temp = open_heredoc_file(error);
	if (fd_file_temp == -1)
		return ;
	g_ms.fd_heredoc = fd_file_temp; //colocar para baixo
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
	if (pid == 0)
		write_heredoc_file(delimiter, &fd_file_temp, cmd);
	waitpid(pid, &status, 0);
	*fd = open(TMP_FILE, O_RDONLY);
	if (*fd != -1)
		g_ms.exit_status = 0;
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (break_heredoc(*fd, fd_file_temp));
	close(fd_file_temp);
	unlink(TMP_FILE);
}
