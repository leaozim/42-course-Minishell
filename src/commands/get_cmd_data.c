/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:19:34 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/23 11:46:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	if (cmd->envp_path != NULL)
		add_free_me(cmd->envp_path);
}

t_bool	get_path(t_commands *cmd)
{
	char	*path_slash;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", cmd->cmd_list[0]);
	if (!cmd->envp_path)
	{
		cmd->path = ft_strdup(path_slash);
		return (free(path_slash), FALSE);
	}
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
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->envp));
}

void	get_cmds(t_commands *cmd, t_list *node)
{
	int	i;

	i = 0;
	g_ms.cmd_count = count_id_token_before_pipe(COMMAND, node);
	cmd->cmd_list = ft_calloc(g_ms.cmd_count + 1, sizeof(char *));
	while (node)
	{
		cmd->token_list = (t_tokens *)node->content;
		if (cmd->token_list->id_token == PIPE)
		{
			break ;
		}
		else if (cmd->token_list->id_token == COMMAND)
		{
			cmd->cmd_list[i] = ft_strdup(cmd->token_list->token);
			ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->cmd_list[i]));
			i++;
		}
		node = node->next;
	}
	cmd->cmd_list[i] = NULL;
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->cmd_list));
}

void	get_argv(t_commands *cmd, t_list *node)
{
	int	count;
	int	i;

	i = 0;
	count = count_tokens_before_pipe(node);
	cmd->argv = ft_calloc(count + 1, sizeof(char *));
	cmd->id = ft_calloc(count, sizeof(int));
	while (node)
	{
		cmd->token_list = (t_tokens *)node->content;
		if (cmd->token_list->id_token == PIPE)
		{
			node = node->next;
			break ;
		}
		cmd->argv[i] = cmd->token_list->token;
		cmd->id[i] = cmd->token_list->id_token;
		node = node->next;
		i++;
	}
	cmd->argv[i] = NULL;
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->argv));
	ft_lstadd_back(&g_ms.free_me, ft_lstnew(cmd->id));
}
