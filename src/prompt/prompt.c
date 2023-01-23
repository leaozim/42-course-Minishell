/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:20:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:38:19 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (ft_strlen(line) == 0 || is_syntax_quote_error(line))
		return (free(line), 1);
	return (0);
}

char	*create_prompt(void)
{
	char	*line;

	line = ft_strdup("");
	while (check_prompt(line))
	{
		line = readline(PROMPT);
		add_history(line);
	}
	return (line);
}
