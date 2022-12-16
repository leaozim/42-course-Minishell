#include "../../include/minishell.h"

int	open_heredoc_file(void)
{
	int	fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd == -1)
	{
		ft_putstr_fd("ola", STDERR_FILENO);
		// *error = TRUE;
	}
	return (fd);
}

void	write_heredoc_file(char *delimiter)
{
	// char *line;
	int fd;

	// signal(SIGQUIT, SIG_IGN);

	signal(SIGINT, signal_break_heredoc);
	fd = open_heredoc_file();
	while (TRUE)
	{
		ms.line_heredoc =  readline("> ");
		if (!ms.line_heredoc)
		{
			free(ms.line_heredoc);
			destroy_heredoc();
			ft_putstr_fd("warning: here-document delimited by end-of-file\n", 2);
			close(fd);
			exit(0);
		}
		// check_prompt(line);
		if (!ft_strcmp(ms.line_heredoc, delimiter))
		{
			free(ms.line_heredoc);
			close(fd);
			break ;
		}
		ft_putendl_fd(ms.line_heredoc, fd);
	}
	exit (0);
}

void	break_heredoc(int fd)
{
	close(fd);
}

void	creat_heredoc(char *delimiter, int *fd, t_bool *error)
{
	int	pid;
	int	status;

	(void)error;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
	if (pid == 0)
		write_heredoc_file(delimiter);
	else
	{
		// signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &status, 0);
		*fd = open(TMP_FILE, O_RDONLY);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
			return (break_heredoc(*fd));
	}
	unlink(TMP_FILE);
}
