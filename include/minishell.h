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


/* -----------------------------------------------------------------------*\
									systen									
\* -----------------------------------------------------------------------*/
void		init_minishell(void);
void		check_arguments(int argc);
void		check_prompt(char *line);
char		*create_prompt(void);
t_bool		is_valid_quoting(char **list);
void		is_erro_sintaxy_quotes(char *line);
void		free_ptrs(char **str);
void		destroy_minishell(void);

/* -----------------------------------------------------------------------*\
									lexer									
\* -----------------------------------------------------------------------*/
void		create_tokens(void);
void		replace_value_inside_quotes(char *list, int old_vle, int new_vle);
int			count_tokens_specific(char *str);
char		*add_spaces_specific_tokens(char *arg, int count);
int			check_len_tab(char **str);
void		reverse_replace(char **table_tokens, int len_tab);
int			*identify_tokens(char **str, int len_tab);
void		create_token_list(char **str, int *id, int len);
t_tokens	*create_content(char *tks, int index);
t_bool		check_for_specific_token(char c);
void		get_quotes(int value, char line, int *i, int **qtt_tokens);
int			check_qtt_to_be_incremented(char *line);

/* -----------------------------------------------------------------------*\
									parser									
\* -----------------------------------------------------------------------*/
int			parser(void);
int			qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens);
void		qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens);
t_bool		is_metachars(int id_tks);
int			is_single_metachar(int id_tokens, int len_tokens);
int			consecutive_metachars(char *token, int id_tokens, int next_id_tokens);
int			error_syntaxy_metachars(t_list *tks, int len_tokens);
void		error_invalid_synax(char *token);
void		error_open_file(char *token, t_bool *error);

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

/* -----------------------------------------------------------------------*\
									expander									
\* -----------------------------------------------------------------------*/
char		*expander(char *token);


/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/

void		print_tokens(void);

#endif
