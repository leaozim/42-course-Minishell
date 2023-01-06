#include "../include/minishell.h"

//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola
#define CMD_NOT_FOUND 127


char	**split_pathname(void)
{
	int		i;
	char	**envp_path_list;
	t_list	*env_node;

	i = 0;
	env_node = ms.env;
	envp_path_list = NULL;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
		{
			envp_path_list = ft_split(env_node->content, ':');
		}
		env_node = env_node->next;
		i++;
	}
	return (envp_path_list);
}

// int	check_path(t_pipex *p, int count)
// {
// 	int	i;

// 	i = 0;
// 	p->bar = ft_strjoin("/", p->splitted_cmd[count][0]);
// 	while (p->envp_path_list[i] != NULL)
// 	{
// 		p->path = ft_strjoin(p->envp_path_list[i], p->bar);
// 		if (access(p->path, F_OK | X_OK) == 0)
// 		{
// 			return (i);
// 		}
// 		i++;
// 		free(p->path);
// 	}
// 	return (CMD_NOT_FOUND);
// }

int	qtt_commands(void)
{
		t_tokens	*next;
	t_list		*node;
	int			i;
	// t_cmd       *cmd;

	i = 0;
	node = ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		printf(BLUE"%s\n"RESET, (char *)next->token);
		if (next->id_token == COMMAND)
			i++;
		node = node->next;
	}
	printf(BLUE"%d\n"RESET, i);
	return (i);
}

char	**create_cmd_list(void)
{
	int			size_comnands;
	char		**arguments;
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	node = ms.tks;
	size_comnands = qtt_commands();
	arguments = ft_calloc(size_comnands + 1, sizeof(char*));
	if (!arguments)
		return (NULL);
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		if (tklist->id_token == COMMAND)
		{
			arguments[i] = ft_strdup(tklist->token);
			i++;
		}
		node = node->next;
	}
	arguments[i] = NULL;
	return (arguments);
}

// int	check_path(char **envp_path_list, int count)
// {
// 	int	i;

// 	i = 0;
// 	p->bar = ft_strjoin("/", p->splitted_cmd[count][0]);
// 	while (p->envp_path_list[i] != NULL)
// 	{
// 		p->path = ft_strjoin(p->envp_path_list[i], p->bar);
// 		if (access(p->path, F_OK | X_OK) == 0)
// 		{
// 			return (i);
// 		}
// 		i++;
// 		free(p->path);
// 	}
// 	return (CMD_NOT_FOUND);
// }

void	executer(void)
{
	char **argc;
	int	i;
	char **env;

	i = 0;
	argc = create_cmd_list();
	while (argc[i])
	{
		printf("argc = %s\n", argc[i]);
		i++;
	}
	env = split_pathname();
	while (env[i])
	{
		printf("env = %s\n", env[i]);
		i++;
	}
	free_ptrs(argc);
	free_ptrs(env);
}

//pipe_number = cmd_number - 1
//




// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH


//open close read
//access dup dup2
//execve fork pipe
//unlink wait waitpid