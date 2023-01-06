#include "../../include/minishell.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola

#define CMD_NOT_FOUND 127


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

char	**split_envp_path(void)
{
	char	**envp_path_list;
	t_list	*env_node;

	env_node = g_ms.env;
	envp_path_list = NULL;
	while (env_node != NULL)
	{
		if (!ft_strncmp(env_node->content, "PATH=", 5))
			envp_path_list = ft_split(env_node->content, ':');
		env_node = env_node->next;
	}
	return (envp_path_list);
}

char	*get_executable_path(char **envp, char **argv)
{
	char	*path_slash;
	char	*executable_path;
	int		i;

	i = 0;
	path_slash = ft_strjoin("/", argv[0]);
	while (envp[i] != NULL)
	{
		executable_path = ft_strjoin(envp[i], path_slash);
		if (access(executable_path, F_OK | X_OK) == 0)
		{
			return (free(path_slash), executable_path);
		}
		i++;
		free(executable_path);
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
	int	i;

	i = -1;
	while (++i < get_cmd_count())
		ft_lstadd_back(&g_ms.commands,
			ft_lstnew(create_cmd_content(argv, envp, path_envp)));
}

void	executer(void)
{
	int		status;
	char	*executable_path;

	if (is_builtins() == TRUE)
		return ;
	argv = create_cmd_list();
	envp = get_envp();
	path_envp = split_envp_path();
	executable_path = get_executable_path(path_envp, argv);
	
	// pid_t	pid;

	// pid = fork();
	// if (pid == 0)
	// {
	// 	execve(executable_path, argv, envp);
	// 	exit(EXIT_FAILURE);
	// }
	// waitpid(pid, &status, 0);
	// free(argv);
	// free(envp);
	// free_ptrs(path_envp);
	// free(executable_path);
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