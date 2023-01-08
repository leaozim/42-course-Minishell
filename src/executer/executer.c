#include "../../include/minishell.h"

void	free_commands(void)
{
	free(g_ms.cmd_data.argv);
	free(g_ms.cmd_data.executable_path);
}

void	close_pipes()
{
	int	i;
	
	i = 0;
	while (i < g_ms.len_pipes)
	{
		close(g_ms.array_fd[i][0]);
		close(g_ms.array_fd[i][1]);
		i++;
	}
	if (g_ms.infd != -1)
		close(g_ms.infd);
	close(g_ms.outfd);
}

void	child_dup_redirection(int index)
{
	if (index == 0)
	{
		dup2(g_ms.infd, STDIN_FILENO);
		dup2(g_ms.array_fd[index][1], STDOUT_FILENO);
	}
	else if (index != (g_ms.len_pipes))
	{
		dup2(g_ms.array_fd[index - 1][0], STDIN_FILENO);
		dup2(g_ms.array_fd[index][1], STDOUT_FILENO);
	}
	else
	{
		dup2(g_ms.array_fd[index - 1][0], STDIN_FILENO);
		dup2(g_ms.outfd, STDOUT_FILENO);
	}
}

void	child_process_execution(void)
{
	if (execve(g_ms.cmd_data.executable_path, g_ms.cmd_data.argv, g_ms.cmd_data.envp) == -1)
	{
		exit(errno);
	}
}

void	child_process_check(int index)
{
	// if (check_path() == FALSE)
	// {
	// 	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	// 	perror(g_ms.cmd_data.argv[0]);
	// 	g_ms.exit_status = COMMAND_NOT_FOUND;
	// }
	child_dup_redirection(index);
	close_pipes();
	child_process_execution();
}

void	fork_check(int index)
{
	if (g_ms.pid_fd[index] < 0)
		exit(EXIT_FAILURE);
	if (g_ms.pid_fd[index] == 0)
	{
		if (g_ms.infd == -1 && index == 0)
		{
			// free_de_tudo
			exit(EXIT_FAILURE);
		}
		child_process_check(index);
	}
}

void	get_cmd_data(void)
{
	get_argv();
	get_cmds();
	if (check_path() == FALSE)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		perror(g_ms.cmd_data.argv[0]);
		g_ms.exit_status = COMMAND_NOT_FOUND;
	}
	printf(BLACK"\nPATH\n"RESET);
	printf(MAGENTA"%s\n"RESET, g_ms.cmd_data.executable_path);
	printf(BLACK"ARGV\n"RESET);
	printf("\n");
}

void	forking(void)
{
	int	index;

	index = 0;
	while (g_ms.cmd_data.node)
	{
		get_cmd_data();
		check_open_files(g_ms.tks, &g_ms.infd, &g_ms.outfd);
		g_ms.pid_fd[index] = fork();
		fork_check(index);
		free_commands();
		index++;
	}
}

void	executer(void)
{
	init_cmd_data();
	forking();
	free_ptrs(g_ms.cmd_data.path_envp);
	free(g_ms.cmd_data.envp);
}

// 	qtt_pipes = id_token_count(PIPE);
// 	qtt_cmd_group = 1;
// 	if (id_token_count(PIPE) > 0)
// 		qtt_cmd_group = qtt_pipes + 1;

//command and search execution

// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH






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