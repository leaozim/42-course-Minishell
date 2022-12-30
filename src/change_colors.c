#include "../include/minishell.h"

static void	msg_available_colors(void)
{
	ft_putstr_fd(MSG_INVALID_COLOR \
	RED"\nred" GREEN"\ngreen" \
	YELLOW"\nyellow" BLUE"\nblue" \
	MAGENTA"\nmagenta" CYAN"\ncyan" \
	RESET"\nreset (default)\n", \
	STDIN_FILENO);
}

void	bash_change_colors(void)
{
	t_list		*node;
	t_tokens	*next;

	node = ms.tks;
	while (node->next)
	{
		next = (t_tokens *)node->next->content;
		if (!ft_strcmp((char *)next->token, "red"))
			ft_putstr_fd(RED, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "green"))
			ft_putstr_fd(GREEN, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "blue"))
			ft_putstr_fd(BLUE, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "yellow"))
			ft_putstr_fd(YELLOW, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "magenta"))
			ft_putstr_fd(MAGENTA, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "cyan"))
			ft_putstr_fd(CYAN, STDIN_FILENO);
		else if (!ft_strcmp((char *)next->token, "reset"))
			ft_putstr_fd(RESET, STDIN_FILENO);
		else
			msg_available_colors();
		node = node->next;
	}
}
