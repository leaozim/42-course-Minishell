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
void			init_minishell(char	**envp);
void			check_arguments(int argc);
char			*create_prompt(void);
t_bool			is_valid_quoting(char **list);
int				is_erro_sintaxy_quotes(char *line);
void			free_ptrs(char **str);
void			destroy_minishell(void);
void			destroy_t_tokens(void *token);
int				check_prompt(char *line);
int				get_size_node(t_list *node);

/* -----------------------------------------------------------------------*\
									lexer									
\* -----------------------------------------------------------------------*/

void			create_tokens(void);
char			*add_marker(char *line);
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
void			handle_signal(void);
void			signal_break_heredoc(int signal);

/* -----------------------------------------------------------------------*\
									expander								
\* -----------------------------------------------------------------------*/
void			expander(void);
char			*minishell_expansion(char *token);
t_bool			is_brace_expansion(char *token, int *i, char **final_str);
int				check_last_expansion_occurrence(char *token);
t_bool			is_envar_between_squote(char *token);
char			*is_envar_expansible(char *token, int *i, char **final_str);
void			expand_check_next_character(char *token, int *i, char **final_str);

/* -----------------------------------------------------------------------*\
									builtins								
\* -----------------------------------------------------------------------*/

void			create_env(char **envp);
t_bool			error_invalid_identifier(char **next, t_list **node, char *cmd);
t_bool			check_error_invalid_identifier(char *token);
void			ft_lstdelone_array(t_list **lst);
void			ft_lstclear_array(t_list **lst);
t_bool			is_builtins(t_list *node);
void			execute_builtins(t_list *node);
// t_bool			is_builtins(t_list *node);
// int				builtin_cd(void);
int				builtin_cd(t_list *node);
void			builtin_env(void);
void			builtin_pwd(void);
void			builtin_exit(t_list *node);
int				builtin_echo(t_list *node);
int				builtin_export(t_list *node);
int				builtin_unset(t_list *node);
t_bool			unset_error_identifier(char **next, t_list **node, char *cmd);
t_bool			check_unset_chr_valid_name(char *token);
void			msg_error_not_a_valid_identifier(char *token, char *cmd);
int				count_quotes_pair(char	*str, char c, int *i);
int				split_count_words(char *str, char c);
char			**split_assign_values(char *str, char c, int count);
void			bash_change_colors(t_list *node);
void			cmd_clear(void);

/* -----------------------------------------------------------------------*\
									executer								
\* -----------------------------------------------------------------------*/

//child_process.c
void			child_dup_redirection(t_list *node, int i);
void			child_process_check(t_list *node, int i);
void			child_process_execution(t_list *node);

//close_pipes.c
void			close_pipes(void);
void			close_fds(void);

//cmd_operations.c
void			get_argv(void);
int				count_tokens_before_pipe(void);
int				count_id_token_before_pipe(int id, t_list *node);
int				count_id_token(int id);
t_bool			is_cmd_executable(t_commands *cmd);
t_bool			check_path(t_commands *cmd);
int				print_array(char **array);

//error_executer.c
void			msg_error_cmd_not_found(int status, char *cmd);

//executer.c
void			executer(void);

//forking.c
void			get_cmd_data(void);
void			fork_check(int i);
void			forking(void);

//free_memory.c
void			free_cmd_data(void);
void			destroy_t_commands(void *cmds);
void			dup_redirection(t_list *node);

//init_data_executer.c
void			init_data_executer(void);


//open_files.c
void			get_files_redirectors(t_list *tks, t_commands *cmd, int *infd, int *outfd);
void			open_files(t_tokens *tks, int *infd, int *outfd, t_commands *cmd);
void			check_redirectors(t_commands *cmd, int	id_token);
void			open_infile(char *file_tks, int flags, int *outfd, t_bool *error);
void			open_outfile(char *file_tks, int flags, int *outfd, t_bool *error);
void			msg_error_open_file(char *token, t_bool *error);
void			msg_error_heredoc(void);
void			create_heredoc(char *delimiter, int *fd, t_bool *error);
void			destroy_heredoc(void);

//path.c
void			get_cmds(t_commands *cmd, t_list *node);
void			get_envp(t_commands *cmd);
void			get_envp_path(t_commands *cmd);
t_bool			get_path(t_commands *cmd);
void			init_fd_data(t_commands *cmd);

//init_pipe_data.c
void			fd_memory_allocate(void);
void			init_pipe_values(void);

//wait_status.c
void			wait_status(void);

/*
APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
*/

void		print_tokens(void);

#endif
