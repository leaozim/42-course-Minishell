#include "../../include/minishell.h"

void	open_outfile(char *file, int flags, int *outfd)
{
	if (g_ms.error_file == FALSE)
	{
		*outfd = open(file, flags, 0644);
		if (*outfd == -1)
			msg_error_open_file(file);
		// else
		// {
		// 	// dup2(STDOUT_FILENO, *outfd);
		// 	dup2(*outfd, STDOUT_FILENO);
		// 	close(*outfd);
		// }
	}
}

void	open_infile(char *file, int flags, int *infd)
{
	*infd = open(file, flags);
	if (*infd == -1)
		msg_error_open_file(file);
	// else
	// {
	// 	// dup2(STDIN_FILENO, *infd);
	// 	dup2(*infd, STDOUT_FILENO);
	// 	close(*infd);
	// }
}

void	open_files(char *redirect, char *file, int *ifd, int *ofd)
{
	if (!ft_strcmp(redirect, ">"))
		open_outfile(file, O_WRONLY | O_CREAT | O_TRUNC, ofd);
	else if (!ft_strcmp(redirect, "<"))
		open_infile(file, O_RDONLY, ifd);
	else if (!ft_strcmp(redirect, ">>"))
		open_outfile(file, O_WRONLY | O_CREAT | O_APPEND, ofd);
	else if (!ft_strcmp(redirect, "<<"))
		create_heredoc(file, ifd);
}

void	check_open_files(char **tks, int *infd, int *outfd)
{
	int	i;

	i = 0;
	g_ms.error_file = FALSE;
	while (tks[i])
	{
		open_files(tks[i], tks[i + 1], infd, outfd);
		i++;
	
	}
}
