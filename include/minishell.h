#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "printf_colors.h"

void		check_arguments(int argc);
void		check_prompt(char *line);
char		*creat_prompt(void);
void		creat_tokens(t_minishell *ms, t_tokens *tokens);
void		replace_value_inside_quotes(char *list, int old_value, int new_value);
t_bool		is_valid_quoting(char **list);
void		free_ptrs(char **str);
void		is_erro_sintaxy_quotes(char *line);
void		init_minishell(t_minishell *ms);
char		*add_spaces_specific_tokens(char *arg, int count);
int			*identify_tokens(char **str, int len_tab);
int			check_qtt_to_be_incremented(char *line);
t_bool		check_for_specific_token(char c);
t_tokens	*creat_content(char *tks, int index);
void		create_token_list(t_minishell *ms, char **str, int *id, int len);
void		destroy_minishell(t_minishell ms);
void		get_quotes(int value, char line, int *i, int *qtt_tokens);
int			check_len_tab(char **str);

/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/
void	print_tokens(t_minishell *ms);

#endif
