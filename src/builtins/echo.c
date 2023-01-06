#include "../../include/minishell.h"

int	is_operand_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_strlen(str) > 1)
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i])
			return (0);
		else
			return (1);
	}
	return (0);
}

void	increment_the_node_while_there_are_n(t_list **node, int *qtt_n)
{
	t_tokens	*next;

	while (*qtt_n < g_ms.len_tokens)
	{
		if ((*node)->next)
		{
			next = (t_tokens *)(*node)->next->content;
			if (is_operand_n(next->token))
				*node = (*node)->next;
			else
				break ;
		}
		*qtt_n += 1;
	}
}

int	print_echo_node(t_list **node, int qtt_n)
{
	t_tokens	*next;
	int			i;

	i = 0;
	while ((*node)->next)
	{
		next = (t_tokens *)(*node)->next->content;
		if (g_ms.len_tokens == 2 && is_operand_n(next->token))
			return (1);
		printf("%s", next->token);
		if (i < g_ms.len_tokens - qtt_n - 2)
			printf(" ");
		(*node) = (*node)->next;
		i++;
	}
	*node = g_ms.tks;
	if ((*node)->next)
	{
		next = (t_tokens *)(*node)->next->content;
		if (!is_operand_n(next->token))
			printf("\n");
	}
	return (0);
}

int	builtin_echo(void)
{
	t_list		*node;
	int			qtt_n;

	node = g_ms.tks;
	qtt_n = 0;
	if (g_ms.len_tokens == 1)
		return (printf("\n"), 0);
	increment_the_node_while_there_are_n(&node, &qtt_n);
	if (print_echo_node(&node, qtt_n))
		return (0);
	return (0);
}
