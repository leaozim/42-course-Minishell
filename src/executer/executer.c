#include "../../include/minishell.h"

// int	check_path(int count)
// {
// 	int     i;
//     char    *bar;

//     //splitted_cmd[count][0] = ls [ls -l -s]
//     //env_path_list[i] = ms.env
//     //p->path = caminho
//     //if (access(path) == 0), sai e retorna a posição
//     //else return (1)

// 	i = 0;
// 	bar = ft_strjoin("/", p->splitted_cmd[count][0]);
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

// int check_path()
// {
    
// }

void    executer(void)
{
    t_tokens	*next;
    t_list		*node;
    int         i;

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
}


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