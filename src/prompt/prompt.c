#include "../../include/minishell.h"

int	check_prompt(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_lstclear(&g_ms.env, free);
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strlen(line) == 0 || is_erro_sintaxy_quotes(line))
		return (free(line), 1);
	return (0);
}

char	*create_prompt(void)
{
	char		*line;

	line = ft_strdup("");
	printf(GREEN"entrou\n"RESET);
	while (check_prompt(line))
	{
		line = readline(PROMPT);
		add_history(line);
	}
	return (line);
}
