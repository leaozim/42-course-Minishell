#include "../../include/minishell.h"

void	get_envp_path(t_commands *cmd)
{
	t_list	*env_node;

	env_node = g_ms.env;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
			cmd->envp_path = ft_split(env_node->content, ':');
		env_node = env_node->next;
	}
}

t_bool	get_path(t_commands *cmd)
{
	char	*path_slash;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", cmd->cmd_list[0]);
	while (cmd->envp_path[i] != NULL)
	{
		cmd->path = ft_strjoin(cmd->envp_path[i], path_slash);
		if (access(cmd->path, F_OK | X_OK) == 0)
		{
			return (free(path_slash), TRUE);
		}
		free(cmd->path);
		i++;
	}
	cmd->path = ft_strdup(cmd->cmd_list[0]);
	return (free(path_slash), FALSE);
}

void	get_envp(t_commands *cmd)
{
	t_list	*env_node;
	size_t	count;
	int		i;

	i = 0;
	env_node = g_ms.env;
	count = ft_lstcount_nodes(env_node);
	cmd->envp = ft_calloc(count + 1, sizeof(char *));
	while (env_node)
	{
		cmd->envp[i] = (char *)env_node->content;
		env_node = env_node->next;
		i++;
	}
	cmd->envp[i] = NULL;
}

int	count_id_token_before_pipe(int id, t_list *node)
{
	t_tokens	*next;
	int			id_count;

	id_count = 0;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == PIPE)
			break ;
		if (next->id_token == id)
			id_count++;
		node = node->next;
	}
	printf(BLUE"%d\n"RESET, id_count);
	return (id_count);
}


void	get_cmds(t_commands *cmd, t_list *node)
{
	int	cmd_count;
	int	i;

	i = 0;
	cmd_count = count_id_token_before_pipe(COMMAND, node);
	cmd->cmd_list = ft_calloc(cmd_count + 1, sizeof(char *));
	while (node)
	{
		cmd->token_list = (t_tokens *)node->content;
		printf("%s\n", cmd->token_list->token);
		if (cmd->token_list->id_token == PIPE)
		{
			break ;
		}
		else if (cmd->token_list->id_token == COMMAND)
		{
			cmd->cmd_list[i] = ft_strdup(cmd->token_list->token);
			i++;
		}
		node = node->next;
	}
	cmd->cmd_list[i] = NULL;
}


// void	get_cmds(void)
// {
// 	int	cmd_count;
// 	int	i;

// 	i = 0;
// 	cmd_count = count_id_token_before_pipe(COMMAND);
// 	g_ms.cmd_data.argv = ft_calloc(cmd_count + 1, sizeof(char *));
// 	while (g_ms.cmd_data.node)
// 	{
// 		g_ms.cmd_data.tklist = (t_tokens *)g_ms.cmd_data.node->content;
// 		if (g_ms.cmd_data.tklist->id_token == PIPE)
// 		{
// 			g_ms.cmd_data.node = g_ms.cmd_data.node->next;
// 			break ;
// 		}
// 		if (g_ms.cmd_data.tklist->id_token == COMMAND)
// 		{
// 			g_ms.cmd_data.argv[i] = g_ms.cmd_data.tklist->token;
// 			i++;
// 		}
// 		g_ms.cmd_data.node = g_ms.cmd_data.node->next;
// 	}
// 	g_ms.cmd_data.argv[i] = NULL;
// }

////////
void	get_argv(void)
{
	t_list	*node;
	int	count;
	int	i;

	i = 0;
	count = count_tokens_before_pipe();
	g_ms.cmd_data.tks = ft_calloc(count + 1, sizeof(char *));
	while (node)
	{
		g_ms.cmd_data.token_list = (t_tokens *)node->content;
		if (g_ms.cmd_data.token_list->id_token == PIPE)
		{
			node = node->next;
			break ;
		}
		g_ms.cmd_data.tks[i] = g_ms.cmd_data.token_list->token;
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
	node = g_ms.tks;
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

int	count_id_token(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			count;

	count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		if (next->id_token == id)
			count++;
		node = node->next;
	}
	return (count);
}

int	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf(RED"%s\n"RESET, array[i]);
		i++;
	}
	printf("\n");
	return (i);
}