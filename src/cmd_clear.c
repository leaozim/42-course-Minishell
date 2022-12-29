#include "../include/minishell.h"

void    cmd_clear(void)
{
    ft_putstr_fd("\e[2J\e[1;1H", STDOUT_FILENO);
}