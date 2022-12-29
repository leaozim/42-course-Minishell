#include "../include/minishell.h"
#include "defines.h"
#include <unistd.h>

void	bash_change_colors()
{
	t_list		*node;
	t_tokens	*next;

	node = ms.tks;
	while (node->next)
	{
		next = (t_tokens *)node->next->content;
		if (!ft_strcmp((char*)next->token,"red"))
			ft_putstr_fd(RED, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "green"))
			ft_putstr_fd(GREEN, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "black"))
			ft_putstr_fd(BLACK, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "blue"))
			ft_putstr_fd(BLUE, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "yellow"))
			ft_putstr_fd(YELLOW, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "magenta"))
			ft_putstr_fd(MAGENTA, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "white"))
			ft_putstr_fd(WHITE, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "cyan"))
			ft_putstr_fd(CYAN, STDIN_FILENO);
		else if (!ft_strcmp((char*)next->token, "reset"))
			ft_putstr_fd(RESET, STDIN_FILENO);
		node = node->next;
	}
}