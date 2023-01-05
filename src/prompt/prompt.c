#include "../../include/minishell.h"

void	check_prompt(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_lstclear(&ms.env, free);
		free(line);
		exit(EXIT_SUCCESS);
	}
}

// char	*get_prompt_line(void)
// {
// 	static char	prompt_line[50];
// 	char		*temp;

// 	temp = ft_strjoin(ARROW, PROMPT);
// 	ft_strlcpy(prompt_line, temp, ft_strlen(temp));
// 	return (prompt_line);
// }

char	*create_prompt(void)
{
	char		*line;

	line = readline(PROMPT);
	check_prompt(line);
	add_history(line);
	return (line);
}
