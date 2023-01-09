#include "../../include/minishell.h"

// void	open_infile(char *file_tks, int flags, int *infd, t_bool *error)
// {
// 	*infd = open(file_tks, flags);
// 	if (*infd == -1)
// 		msg_error_open_file(file_tks, error);
// }

// void	open_outfile(char *file_tks, int flags, int *outfd, t_bool *error)
// {
// 	*outfd = open(file_tks, flags, 0644);
// 	if (*outfd == -1 || (error))
// 		msg_error_open_file(file_tks, error);
// }

// void	open_files(t_tokens *tks, int *ifd, int *ofd)
// {	
// 	if (tks->id_token == FILE_IN && !tks->err)
// 		open_infile(tks->token, O_RDONLY, ifd, &tks->err);
// 	if (tks->id_token == FILE_OUT && !tks->err)
// 		open_outfile(tks->token, O_CREAT | O_WRONLY | O_TRUNC, ofd, &tks->err);
// 	if (tks->id_token == FILE_APPEND && !tks->err)
// 		open_outfile(tks->token, O_CREAT | O_WRONLY | O_APPEND, ofd, &tks->err);
// 	if (tks->id_token == DELIMITER && !tks->err)
// 		create_heredoc(tks->token, ifd, &tks->err);

void	open_outfile(char *file, int flags, int *outfd)
{
	if (g_ms.error_file == FALSE)
	{
		*outfd = open(file, flags, 0644);
		if (*outfd == -1)
			msg_error_open_file(file);
		// else
		// {
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
	// 	dup2(*infd, STDIN_FILENO);
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
// #include <cstdio>
void	check_open_files(char **tks, int *infd, int *outfd)
{
	int	i;

	i = 0;
	g_ms.error_file = FALSE;
	printf("%s\n", tks[i]);
	while (tks[i])
	{
		printf("aq\n");
		open_files(tks[i], tks[i + 1], infd, outfd);
		i++;
	
	}
}
