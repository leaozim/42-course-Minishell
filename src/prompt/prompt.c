#include "../../include/minishell.h"
#include <unistd.h>

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_lstclear(&ms.env, free);
		free(line);
		exit(EXIT_FAILURE);
	}
}

char	*get_prompt_line(void)
{
	static char	prompt_line[50];
	char		*temp;
	char		*status_line;

	status_line = ft_itoa(ms.exit_status);
	temp = ft_strjoin(CIRCLE, status_line);
	free(status_line);
	ft_strupdate(&temp, ft_strjoin(temp, PROMPT));
	ft_strlcpy(prompt_line, temp, ft_strlen(temp));
	free(temp);
	return (prompt_line);
}

// Minishell (127)

char	*create_prompt(void)
{
	char		*line;

	line = readline(get_prompt_line());
	check_prompt(line);
	add_history(line);
	return (line);
}
