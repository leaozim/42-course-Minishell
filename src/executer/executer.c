#include "../../include/minishell.h"

//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola

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

void	free_utils(void)
{
	free(g_ms.cmd_data.argv);
	free_ptrs(g_ms.cmd_data.path_envp);
	free(g_ms.cmd_data.executable_path);
}

void	get_argv(void)
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

void	get_cmd_data(void)
{
	get_argv();
	split_envp_path();
	if (get_executable_path() == FALSE)
		printf("command not found\n");
	printf(BLACK"\nPATH\n"RESET);
	printf(MAGENTA"%s\n"RESET, g_ms.cmd_data.executable_path);
	printf(BLACK"ARGV\n"RESET);
	// print_array(g_ms.cmd_data.argv);
	printf("\n");
}

void	executer(void)
{
	get_envp(g_ms.cmd_data);
	g_ms.cmd_data.node = g_ms.tks;
	g_ms.cmd_data.tklist = (t_tokens *)g_ms.cmd_data.node->content;
	g_ms.cmd_data.tklist->index = 0;
	while (g_ms.cmd_data.tklist->index != g_ms.len_tokens - 1)
	{
		get_cmd_data();
		free_utils();
	}
	free(g_ms.cmd_data.envp);

}

	// pid_t	pid;
	// int		status;

	// pid = fork();

	// if (pid == 0)
	// {
	// 	execve(cmd_data.executable_path, cmd_data.argv, cmd_data.envp);
	// 	exit(EXIT_FAILURE);
	// }
	// waitpid(pid, &status, 0);

	// if (is_builtins() == TRUE)
	// 	return ;
	// free(cmd_data.executable_path);








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


//command and search executing

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


// char	**get_array_token()
// {
// 	char			**array_token;
// 	t_tokens		*next;
// 	t_list			*node;
// 	int			i;

// 	node = g_ms.tks;
// 	i = 0;
// 	array_token = ft_calloc(g_ms.len_tokens + 1, sizeof(char *));
// 	while (node)
// 	{
// 		next = (t_tokens *)node->content;
// 		array_token[i] = next->token;
// 		node = node->next;
// 		i++;
// 	}
// 	array_token[i] = NULL;
// 	return (array_token);
// }