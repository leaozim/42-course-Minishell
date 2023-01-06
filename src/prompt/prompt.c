#include "../../include/minishell.h"

int	check_prompt(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_lstclear(&ms.env, NULL);
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strlen(line) == 0 || is_erro_sintaxy_quotes(line))
		return (free(line), 1);
	return (0);
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

	line = ft_strdup("");
	while (check_prompt(line))
	{
		line = readline(PROMPT);
		add_history(line);
	}
	return (line);
}
