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
char		*create_prompt(void);
void		create_tokens(t_minishell *ms);
void		replace_value_inside_quotes(char *list, int old_vle, int new_vle);
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
void		get_quotes(int value, char line, int *i, int **qtt_tokens);
// void		count_tokens_specific(char *str, int *qtt_tokens);
int			count_tokens_specific(char *str);
int			check_len_tab(char **str);
void		reverse_replace(char **table_tokens, int len_tab);
char		*expander(char *token);

/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/

void		print_tokens(t_minishell *ms);

char *expander(char *token);

#endif
