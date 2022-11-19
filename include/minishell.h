#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "printf_colors.h"

void	check_program(int argc);
void	check_prompt(char *line);
void	creat_prompt(void);
void    tokens(int argc, char **argv);

#endif