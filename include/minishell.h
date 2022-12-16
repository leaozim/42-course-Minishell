#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "printf_colors.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void		check_arguments(int argc);
void		check_prompt(char *line);
char		*create_prompt(void);
void		create_tokens(void);
void		replace_value_inside_quotes(char *list, int old_vle, int new_vle);
t_bool		is_valid_quoting(char **list);
void		free_ptrs(char **str);
void		is_erro_sintaxy_quotes(char *line);
void		init_minishell(void);
char		*add_spaces_specific_tokens(char *arg, int count);
int			*identify_tokens(char **str, int len_tab);
int			check_qtt_to_be_incremented(char *line);
t_bool		check_for_specific_token(char c);
t_tokens	*creat_content(char *tks, int index);
void		create_token_list(char **str, int *id, int len);
void		get_quotes(int value, char line, int *i, int **qtt_tokens);
int			count_tokens_specific(char *str);
int			check_len_tab(char **str);
void		reverse_replace(char **table_tokens, int len_tab);
int			parser(void);
void		destroy_minishell(void);
int			qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens);
void		qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens);
int			is_single_metachar(int id_tokens, int len_tokens);
t_bool		is_metachars(int id_tks);
int			error_syntaxy_metachars(t_list *tks, int len_tokens);
int			consecutive_metachars(int id_tokens, int next_id_tokens);
char		*expand_variables(char *token);
char		*expander(char *token);
void		open_infile(char *file_tks, int flags, int *outfd, t_bool *err);
void		open_outfile(char *file_tks, int flags, int *outfd, t_bool *err);
void		check_open_files(t_list *tks, int *infd, int *outfd);
void		open_files(t_tokens *tks, int *infd, int *outfd);
void		open_outfile(char *file_tks, int flags, int *outfd, t_bool *error);
void		open_infile(char *file_tks, int flags, int *infd, t_bool *error);
void		creat_heredoc(char *delimiter, int *fd, t_bool *error);
void		handle_signal(void);
void		signal_break_heredoc(int signal);
void		destroy_heredoc(void);

/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/

void		print_tokens(void);

#endif
