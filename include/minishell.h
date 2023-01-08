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
# include <errno.h>


/* -----------------------------------------------------------------------*\
									system									
\* -----------------------------------------------------------------------*/
void		init_minishell(char	**envp);
void		check_arguments(int argc);
char		*create_prompt(void);
t_bool		is_valid_quoting(char **list);
int			is_erro_sintaxy_quotes(char *line);
void		free_ptrs(char **str);
void		destroy_minishell(void);
void		destroy_t_tokens(void *token);
int			check_prompt(char *line);

/* -----------------------------------------------------------------------*\
									lexer									
\* -----------------------------------------------------------------------*/

void			create_tokens(void);
char			*add_marker(char *line);
// char			*add_marker(char *line, int old_vle, int new_vle);
char			*add_chrs_in_specific_position(char *line, int index, char characters);
void			replace_value_inside_quotes(char *list, int old_vle, int new_vle);
int				count_specific_tokens(char *str);
char			*add_spaces_specific_tokens(char *arg, int count);
int				check_len_tab(char **str);
void			reverse_replace(char **table_tokens, int len_tab);
int				*identify_tokens(char **str, int len_tab);
void			create_token_list(char **str, int *id, int len);
t_tokens		*create_content(char *tks, int index, int id);
t_bool			check_for_specific_token(char c);
void			get_quotes(int value, char line, int *i, int **qtt_tokens);
int				check_qtt_to_be_incremented(char *line);
void			join_tokens(t_list **tks);
t_bool			check_for_specific_token2(char c);
void			reidentify_some_tokens(t_list *tks);

/* -----------------------------------------------------------------------*\
									parser									
\* -----------------------------------------------------------------------*/
int				parser(void);
int				qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens);
void			qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens);
t_bool			is_metachars(int id_tks);
int				is_single_metachar(char *token, int id, int len_tokens);
int				consecutive_metachars(char *token, char *next_token,int id, int next_id);
int				error_syntaxy_metachars(t_list *tks, int len_tokens);
void			msg_error_invalid_synax(char *token);
void			msg_error_open_file(char *token, t_bool *error);
void			msg_error_heredoc(void);
void			check_open_files(t_list *tks, int *infd, int *outfd);

void			open_files(t_tokens *tks, int *infd, int *outfd);
void			open_infile(char *file_tks, int flags, int *outfd, t_bool *err);
void			open_outfile(char *file_tks, int flags, int *outfd, t_bool *error);

void			create_heredoc(char *delimiter, int *fd, t_bool *error);
void			handle_signal(void);
void			signal_break_heredoc(int signal);
void			destroy_heredoc(void);

/* -----------------------------------------------------------------------*\
									expander								
\* -----------------------------------------------------------------------*/
void            expander(void);
char            *minishell_expansion(char *token);
t_bool          is_brace_expansion(char *token, int *i, char **final_str);
int             check_last_expansion_occurrence(char *token);
t_bool          is_envar_between_squote(char *token);
char            *is_envar_expansible(char *token, int *i, char **final_str);
void            expand_check_next_character(char *token, int *i, char **final_str);

/* -----------------------------------------------------------------------*\
									builtins								
\* -----------------------------------------------------------------------*/

void			create_env(char **envp);
t_bool			error_invalid_identifier(t_tokens **next, t_list **node, char *cmd);
t_bool			check_error_invalid_identifier(char *token);
void			ft_lstdelone_array(t_list **lst);
void			ft_lstclear_array(t_list **lst);
t_bool			is_builtins(void);
int				builtin_cd(void);
void			builtin_env(void);
void			builtin_pwd(void);
void			builtin_exit(void);
int				builtin_echo(void);
int				builtin_export(void);
int	    		builtin_unset(void);
void			msg_error_not_a_valid_identifier(char *token, char *cmd);
int				count_quotes_pair(char	*str, char c, int *i);
int				split_count_words(char *str, char c);
char			**split_assign_values(char *str, char c, int count);
void			bash_change_colors(void);
void			cmd_clear(void);

void			executer(void);
int				count_id_token_before_pipe(int id);
int				count_tokens_before_pipe(void);
void			split_envp_path();
void			get_envp();
void			get_cmds();
void			get_argv(void);
t_bool			get_executable_path();
int				print_array(char **array);
t_bool			check_path(void);
int				count_id_token(int id);
void			init_cmd_data(void);

/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/

void		print_tokens(void);

#endif
