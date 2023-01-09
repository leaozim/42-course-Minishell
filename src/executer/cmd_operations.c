#include "../../include/minishell.h"

void	get_cmds(void)
{
	int	cmd_count;
	int	i;

	i = 0;
	cmd_count = count_id_token_before_pipe(COMMAND);
	g_ms.cmd_data.argv = ft_calloc(cmd_count + 1, sizeof(char *));
	while (g_ms.cmd_data.node)
	{
		g_ms.cmd_data.tklist = (t_tokens *)g_ms.cmd_data.node->content;
		if (g_ms.cmd_data.tklist->id_token == PIPE)
		{
			g_ms.cmd_data.node = g_ms.cmd_data.node->next;
			break ;
		}
		if (g_ms.cmd_data.tklist->id_token == COMMAND)
		{
			g_ms.cmd_data.argv[i] = g_ms.cmd_data.tklist->token;
			i++;
		}
		g_ms.cmd_data.node = g_ms.cmd_data.node->next;
	}
	g_ms.cmd_data.argv[i] = NULL;
}

void	get_argv(void)
{
	t_list	*node;
	int	count;
	int	i;

	i = 0;
	count = count_tokens_before_pipe();
	node = g_ms.cmd_data.node;
	g_ms.cmd_data.tks = ft_calloc(count + 1, sizeof(char *));
	while (node)
	{
		g_ms.cmd_data.tklist = (t_tokens *)node->content;
		if (g_ms.cmd_data.tklist->id_token == PIPE)
		{
			node = node->next;
			break ;
		}
		g_ms.cmd_data.tks[i] = g_ms.cmd_data.tklist->token;
		node = node->next;
		i++;
	}
	g_ms.cmd_data.tks[i] = NULL;
}

int	count_tokens_before_pipe(void)
{
	t_tokens	*next;
	t_list		*node;
	int			count;

	count = 0;
	node = g_ms.cmd_data.node;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		node = node->next;
		count++;
	}
	return (count);
}

int	count_id_token_before_pipe(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			id_count;

	id_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	return (id_count);
}

int	count_id_token(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			id_count;

	id_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	return (id_count);
}

t_bool	is_cmd_with_slash_executable(void)
{
	if (ft_strchr(g_ms.cmd_data.argv[0], SLASH))
	{
		g_ms.cmd_data.executable_path = ft_strdup(g_ms.cmd_data.argv[0]);
		if (access(g_ms.cmd_data.executable_path, F_OK | X_OK) == 0)
			return (TRUE);
		else
			free(g_ms.cmd_data.executable_path);
	}
	return (FALSE);
}

t_bool	check_path(void)
{
	if (is_cmd_with_slash_executable() == TRUE)
		return (TRUE);
	else if (get_executable_path() == TRUE)
		return (TRUE);
	else if (is_builtins() == TRUE)
		return (TRUE);
	return (FALSE);
}

int	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf(RED"%s "RESET, array[i]);
		i++;
	}
	printf("\n");
	return (i);
}