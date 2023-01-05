#include "../../include/minishell.h"

void	destroy_heredoc(void)
{
	ft_lstclear(&ms.tks, destroy_t_tokens);
	free(ms.tab_tokens);
	close(ms.fd_heredoc);
	free(ms.tab_id);
	ft_lstclear(&ms.env, NULL);
}

void	break_heredoc(int fd, int fd_file_temp)
{
	close(fd);
	close (fd_file_temp);
	unlink(TMP_FILE);
	ms.exit_status = 130;
}

int	open_heredoc_file(t_bool *error)
{
	int	fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd == -1)
		msg_error_open_file(TMP_FILE, error);
	return (fd);
}

void	write_heredoc_file(char *delimiter, int *fd)
{
	signal(SIGINT, signal_break_heredoc);
	while (TRUE)
	{
		ms.line_heredoc = readline("> ");
		if (!ms.line_heredoc)
		{
			free(ms.line_heredoc);
			destroy_heredoc();
			msg_error_heredoc();
			close(*fd);
			exit(0);
		}
		if (!ft_strcmp(ms.line_heredoc, delimiter))
		{
			free(ms.line_heredoc);
			close(*fd);
			destroy_heredoc();
			break ;
		}
		ft_putendl_fd(ms.line_heredoc, *fd);
		free(ms.line_heredoc);
	}
	close(ms.fd_heredoc);
	exit (0);
}

void	creat_heredoc(char *delimiter, int *fd, t_bool *error)
{
	int	pid;
	int	status;
	int	fd_file_temp;

	signal(SIGINT, SIG_IGN);
	fd_file_temp = open_heredoc_file(error);
	if (fd_file_temp == -1)
		return ;
	ms.fd_heredoc = fd_file_temp;
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
	if (pid == 0)
		write_heredoc_file(delimiter, &fd_file_temp);	
	waitpid (pid, &status, 0);
	*fd = open(TMP_FILE, O_RDONLY);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (break_heredoc(*fd, fd_file_temp));
	close(*fd);
	close (fd_file_temp);
	unlink (TMP_FILE);
}
