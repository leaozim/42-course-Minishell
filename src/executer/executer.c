#include "../../include/minishell.h"

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

t_commands	*create_cmd_content(char **argv, char **envp, char **path_envp)
{
	t_commands	*content;

	content = ft_calloc(1, sizeof(t_commands));
	content->argv = argv;
	content->envp = envp;
	content->path_envp = path_envp;
	return (content);
}

void	create_cmd_list(char **argv, char **envp, char **path_envp)
{
	int			i;
	t_list		*node;
	t_tokens	*tklist;
	int			qtt_cmd_group;
	int			qtt_pipes;
	// int			

	i = -1;
	node = g_ms.tks;
	qtt_pipes = id_token_count(PIPE);
	qtt_cmd_group = 1;
	if (id_token_count(PIPE) > 0)
		qtt_cmd_group = qtt_pipes + 1; 
	while (++i < id_token_count(COMMAND))
	{
		tklist = (t_tokens *)node->content;
		if (tklist->id_token == PIPE)
		{
			node = node->next;
			qtt_cmd_group--;
			i++;
		}
		ft_lstadd_back(&g_ms.commands,
		ft_lstnew(create_cmd_content(argv, envp, path_envp)));
	}
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

void	executer(void)
{
	t_utils	cmd_data;
	int		status;

	if (is_builtins() == TRUE)
		return ;
	get_cmd_list(&cmd_data);
	get_envp(&cmd_data);
	split_envp_path(&cmd_data);
	get_executable_path(&cmd_data);
	print_array(cmd_data.argv);
	print_array(cmd_data.envp);
	// printf("%s\n", cmd_data.executable_path);
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_data.executable_path, cmd_data.argv, cmd_data.envp);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	free(cmd_data.argv);
	free(cmd_data.envp);
	free_ptrs(cmd_data.path_envp);
	free(cmd_data.executable_path);
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