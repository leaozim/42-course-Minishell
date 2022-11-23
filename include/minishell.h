#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "printf_colors.h"

void	check_arguments(int argc);
void	check_prompt(char *line);
char	*creat_prompt(void);
void	tokens(int argc, char **argv);
void	handle_quoting(char *list, int original_value, int replaced_value);

t_bool	is_valid_quoting(char **list);
void	free_ptrs(char **str);
void	is_erro_sintaxy_quotes(char *line_terminal);
char	*add_spaces_at_specific_char(char *arg, int token_count);

#endif
