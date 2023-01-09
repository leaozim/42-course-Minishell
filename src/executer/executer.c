#include "../../include/minishell.h"

void	free_commands(void)
{
	free(g_ms.cmd_data.argv);
	free(g_ms.cmd_data.executable_path);
}

void	get_cmd_data(void)
{
	get_argv();
	get_cmds();
	printf("\n");
}

void	executer(void)
{
	init_cmd_data();
	forking();
	close_pipes();
	wait_status();

	free_ptrs(g_ms.cmd_data.path_envp);
	free(g_ms.cmd_data.envp);
	ft_free_int_array(g_ms.array_fd, g_ms.len_pipes + 1);
	free(g_ms.pid_fd);
	free(g_ms.cmd_data.tks);
}

//command and search execution

// if (slash)
//     já tem o caminho

// if (builtin)
//     is_builtin

// else
//     procurar no PATH


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
