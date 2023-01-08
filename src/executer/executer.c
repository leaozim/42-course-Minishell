#include "../../include/minishell.h"
#include "defines.h"

//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola

#define CMD_NOT_FOUND 127

void	split_envp_path(t_utils *data)
{
	t_list	*env_node;

	env_node = g_ms.env;
	data->path_envp = NULL;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
			data->path_envp = ft_split(env_node->content, ':');
		env_node = env_node->next;
	}

}

char	*get_executable_path(t_utils *data)
{
	char	*path_slash;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", data->argv[0]);
	while (data->path_envp[i] != NULL)
	{
		data->executable_path = ft_strjoin(data->path_envp[i], path_slash);
		if (access(data->executable_path, F_OK | X_OK) == 0)
		{
			return (free(path_slash), data->executable_path);
		}
		i++;
		free(data->executable_path);
	}
	return (free(path_slash), NULL);
}

// t_commands	*create_cmd_content(char **argv, char **envp, char **path_envp)
// {
// 	t_commands	*content;

// 	content = ft_calloc(1, sizeof(t_commands));
// 	content->argv = argv;
// 	content->envp = envp;
// 	content->path_envp = path_envp;
// 	return (content);
// }

// void	create_cmd_list(char **argv, char **envp, char **path_envp)
// {
// 	int			i;
// 	t_list		*node;
// 	t_tokens	*tklist;
// 	int			qtt_cmd_group;
// 	int			qtt_pipes;
// 	// int			

// 	i = -1;
// 	node = g_ms.tks;
// 	qtt_pipes = id_token_count(PIPE);
// 	qtt_cmd_group = 1;
// 	if (id_token_count(PIPE) > 0)
// 		qtt_cmd_group = qtt_pipes + 1; 
// 	while (++i < id_token_count(COMMAND))
// 	{
// 		tklist = (t_tokens *)node->content;
// 		if (tklist->id_token == PIPE)
// 		{
// 			node = node->next;
// 			qtt_cmd_group--;
// 			i++;
// 		}
// 		ft_lstadd_back(&g_ms.commands,
// 		ft_lstnew(create_cmd_content(argv, envp, path_envp)));
// 	}
// }

int	id_token_count2(int id)
{
	t_tokens	*next;
	t_list		*node;
	int			id_count;

	id_count = 0;
	node = g_ms.tks;
	while (node)
	{
		next = (t_tokens *)node->content;
		while (next->id_token != PIPE)
		{
			if (next->id_token == id)
				id_count++;
			node = node->next;
		}
		node = node->next;
	}
	return (id_count);
}

void	get_cmd_list2(t_utils *data)
{
	int			cmd_count;
	t_list		*node;
	t_tokens	*tklist;
	int			i;

	cmd_count = id_token_count2(COMMAND);
	data->argv = ft_calloc(cmd_count + 1, sizeof(char*));
	node = g_ms.tks;
	i = 0;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		while (tklist->id_token != PIPE) 
		{
			if (tklist->id_token == COMMAND)
			{
				data->argv[i] = tklist->token;
				i++;
			}
			node = node->next;
		}
		node = node->next;
	}
	data->argv[i] = NULL;
}



t_commands	*create_cmd_content(char **cmd)
{
	t_commands	*content;

	content = ft_calloc(1, sizeof(t_commands));
	// content->cmd = cmd;
	content->argv = cmd;
	content->envp = NULL;
	content->path_envp = NULL;
	return (content);
}

int	print_array(char **array)
{
	int i = 0;
	while(array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (i);
}


void	print_cmds(void)
{
	t_list		*node;
	t_commands	*tklist;

	node = g_ms.commands;
	if (!g_ms.commands)
		return ;
	tklist = (t_commands *)node->content;
	// printf("tokens = %s\n", tklist->cmd);	
	while (node)
	{
		tklist = (t_commands *)node->content;
		printf("argv = %s\n", tklist->argv[0]);
		printf("argv = %s\n", tklist->argv[1]);
			printf("argv = %s\n", tklist->argv[2]);
		printf("argv = %s\n", tklist->argv[3]);
		// printf("id     = %d\n", tklist->id_token);
		node = node->next;
	}
}

void	create_commands(t_utils	*cmd_list)
{
	t_list		*node;
	t_tokens	*tklist;

	node = g_ms.tks;
	// while (node )
	// {
		if (!node)
			return ; 
		while (((t_tokens *)node->content)->id_token != PIPE)
		{
			tklist = (t_tokens *)node->content;
			check_open_files(g_ms.tks, &g_ms.infd, &g_ms.outfd);
			if (tklist->id_token == COMMAND)
			{
				ft_lstadd_back(&g_ms.commands,
					ft_lstnew(create_cmd_content(cmd_list->argv)));
			// printf("cmd = %s\n", tklist->token);
			}
			if (!node->next)
				break ;
			// node = node->next;
			node = node->next;

		}
		if (((t_tokens *)node->content)->id_token == PIPE)
		{
			node = node->next;
			create_commands(cmd_list);
		}
}

void	executer(void)
{
	t_utils	cmd_data;
	// int		status;

	get_cmd_list2(&cmd_data);
	// get_cmd_list2(&cmd_data);
	create_commands(&cmd_data);
	print_cmds();
	// check_open_files(g_ms.tks, &g_ms.infd, &g_ms.outfd);
	// if (is_builtins() == TRUE)
	// 	return ;
	// get_cmd_list(&cmd_data);
	// get_envp(&cmd_data);
	// split_envp_path(&cmd_data);
	// get_executable_path(&cmd_data);
	// print_array(cmd_data.argv);
	// print_array(cmd_data.envp);
	// printf("%s\n", cmd_data.executable_path);
	// pid_t	pid;

	// pid = fork();
	// if (pid == 0)
	// {
	// 	execve(cmd_data.executable_path, cmd_data.argv, cmd_data.envp);
	// 	exit(EXIT_FAILURE);
	// }
	// waitpid(pid, &status, 0);
	// free(cmd_data.argv);
	// free(cmd_data.envp);
	// free_ptrs(cmd_data.path_envp);
	// free(cmd_data.executable_path);
}

//PASSOS
// ver se é builtin
// status de saída


//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola

//1) char ** do comando e dos argumentos do execve
//2) se é builtin, não vai pro execve
//3)

// execve("/usr/bin/ls", {"ls", "-l", "-s", "-h", 0}, envp);
// echo -n > test2 > test3 oi ola | ls | grep obj > test1 | ls -l


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