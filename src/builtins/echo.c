#include "../../include/minishell.h"

int	echo(void)
{
	// t_tokens	*tklist;
	t_tokens	*next;
	t_list		*node;

	node = ms.tks;
	while (node->next)
	{
		if (node->next)
			next = (t_tokens *)node->next->content;
		// tklist = (t_tokens *)node->content;
		printf("%s", next->token);
		if (node->next)
			printf(" ");
		node = node->next;
	}
	node = ms.tks;
	next = (t_tokens *)node->next->content;
	if (ft_strcmp("-n", next->token))
		printf("\n");
	return (0);
}
// int	echo(void)
// {
// 	t_tokens	*token;
// 	t_list		*node;

// 	node = ms.tks;
// 	// if ()

// 	return (0);
// }

// void	is_builtins(t_st)
