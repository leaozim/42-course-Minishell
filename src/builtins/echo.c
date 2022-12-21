#include "../../include/minishell.h"

int	echo(void)
{
	t_tokens	*tklist;
	t_tokens	*next;
	t_list		*node;

	node = ms.tks;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		printf("%s", tklist->token);
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

void	is_builtins(void)
{
	t_list		*node;
	t_tokens	*tklist;

	node = ms.tks;
	tklist = (t_tokens *)node->content;
	printf("tokens = %s\n", tklist->token);
	if (!ft_strcmp("echo", tklist->token))
	{
		echo();
	}
}
