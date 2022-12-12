// #include "../../include/minishell.h"

// int	open_heredoc_file(t_bool *error)
// {
// 	int	fd;

// 	fd = open(TMP_FILE,  O_CREAT | O_RDWR | O_TRUNC, 0664);
// 	if (fd == -1)
// 	{
// 		ft_putstr_fd("ola", STDERR_FILENO);
// 		*error = TRUE;
// 	}
// 	return (fd);
// }

// void	write_heredoc_file(int fd, int delimiter)
// {
// 	char *line;

// 	(void)delimiter;
// 	while (TRUE)
// 	{
// 		line =  readline("> ");
// 		write(fd, line, ft_strlen(line));
// 		close(fd);

// 	}
// }

// void	creat_heredoc(int delimiter, int *in_fd, t_bool *error)
// {
// 	int	pid;
// 	int	fd;

// 	(void)in_fd;
// 	fd = open_heredoc_file(error);
// 	// printf("oi\n");
// 	pid = fork();
// 	if (pid < 0)
// 		ft_putstr_fd("fork: creating error\n", STDERR_FILENO);
// 	if (pid == 0)
// 	{
// 		write_heredoc_file(fd, delimiter);
// 	}
// 	// else
// }