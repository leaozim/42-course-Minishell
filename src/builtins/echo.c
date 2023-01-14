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
	char	*next_cmd;

	while (*qtt_n < g_ms.size_node_builtin)
	{
		if ((*node)->next)
		{
			next_cmd = (char *)(*node)->next->content;
			if (is_operand_n(next_cmd))
				*node = (*node)->next;
			else
				break ;
		}
		*qtt_n += 1;
	}
}

int	print_echo_node(t_list **node, int qtt_n)
{
	char	*next_cmd;
	int		i;
	t_list	*node_tks;

	i = 0;
	while ((*node)->next)
	{
		next_cmd = (char *)(*node)->next->content;
		if (g_ms.size_node_builtin == 2 && is_operand_n((*node)->next->content))
			return (1);
		printf("%s", next_cmd);
		if (i < g_ms.size_node_builtin - qtt_n - 2)
			printf(" ");
		(*node) = (*node)->next;
		i++;
	}
	node_tks = g_ms.cmd_table;
	*node = (((t_commands *)node_tks->content)->builtins_cmd_list);
	if ((*node)->next)
	{
		next_cmd = (*node)->next->content;
		if (!is_operand_n(next_cmd))
			printf("\n");
	}
	return (0);
}

int	builtin_echo(t_list *cmd_builtins)
{
	int			qtt_n;

	qtt_n = 0;
	if (g_ms.size_node_builtin == 1)
		return (ft_putchar_fd('\n', STDOUT_FILENO), 0);
	increment_the_node_while_there_are_n(&cmd_builtins, &qtt_n);
	if (print_echo_node(&cmd_builtins, qtt_n))
		return (0);
	return (0);
}
