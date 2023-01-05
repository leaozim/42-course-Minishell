#include "../include/minishell.h"
#include "defines.h"
#include <unistd.h>

//caso de sucesso -> (comando simples + lista de argumentos)
//ex: echo -n oi ola

void    executer(void)
{
    t_tokens	*next;
    t_list		*node;
    int         i;
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