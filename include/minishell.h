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
// char	*create_prompt(t_minishell ms);
char	*create_prompt(void);
// void	tokens(char *argv);
void	tokens(t_minishell *ms);
// void	handle_quoting(char *list, int original_value, int replaced_value);
void	replace_value_inside_quotes(char *list, int old_value, int new_value);
t_bool	is_valid_quoting(char **list);
void	free_ptrs(char **str);
void	is_erro_sintaxy_quotes(char *line);
void	init_minishell(t_minishell *ms);
char	*add_spaces_at_specific_tokens(char *arg, int count);

#endif
