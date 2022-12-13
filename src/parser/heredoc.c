#include "../../include/minishell.h"
#include <stdio.h>
#include <unistd.h>

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
	char *line;
	int fd;

	fd = open_heredoc_file();
	while (TRUE)
	{
		line =  readline("> ");
		check_prompt(line);
		if (!ft_strcmp(line, delimiter))
		{
			free(line);
			close(fd);
			break ;
		}
		ft_putendl_fd(line, fd);
	}
	exit (0);
}

void	creat_heredoc(char *delimiter, int *fd, t_bool *error)
{
	int	pid;
	int	status;

	(void)error;
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
	if (pid == 0)
		write_heredoc_file(delimiter);
	else
	{
		waitpid(pid, &status, 0);
		*fd = open(TMP_FILE, O_RDONLY);
	}
	unlink(TMP_FILE);
}
