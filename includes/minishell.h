/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:17 by etomiyos          #+#    #+#             */
/*   Updated: 2023/01/22 15:21:18 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/stat.h>
# include <sys/types.h>

/* -----------------------------------------------------------------------*\
									system
\* -----------------------------------------------------------------------*/

int			is_syntax_quote_error(char *line);
int			check_prompt(char *line);
int			get_size_node(t_list *node);
char		*create_prompt(void);
void		init_minishell(char **argv, char **envp);
void		check_arguments(int argc);
void		free_ptrs(char **str);
void		destroy_minishell(void);
void		destroy_t_tokens(void *token);
t_bool		is_valid_quoting(char **list);

/* -----------------------------------------------------------------------*\
									lexer
\* -----------------------------------------------------------------------*/

int			check_qtt_to_be_incremented(char *line);
int			count_specific_tokens(char *str);
int			check_len_tab(char **str);
int			*identify_tokens(char **str, int len_tab);
char		*add_marker(char *line);
char		*add_spaces_specific_tokens(char *arg, int count);
char		*add_chrs_in_specific_position(char *line, int index, char c);
void		create_tokens(void);
void		replace_value_inside_quotes(char *list, int old_vle, int new_vle);
void		reverse_replace(char **table_tokens, int len_tab);
void		create_token_list(char **str, int *id, int len);
void		get_quotes(int value, char line, int *i, int **qtt_tokens);
void		reidentify_some_tokens(t_list *tks);
void		join_tokens(t_list **tks);
t_bool		check_for_specific_token2(char c);
t_bool		check_for_specific_token(char c);
t_tokens	*create_content(char *tks, int index, int id);

/* -----------------------------------------------------------------------*\
									parser
\* -----------------------------------------------------------------------*/

int			parser(void);
int			qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens);
int			is_single_metachar(char *token, int id, int len_tokens);
int			consecutive_metachars(char *tk, char *next_tk, int id, int next_id);
int			error_syntaxy_metachars(t_list *tks, int len_tokens);
void		qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens);
void		msg_error_invalid_synax(char *token);
void		handle_signal(void);
void		signal_break_heredoc(int signal);
t_bool		is_metachars(int id_tks);

/* -----------------------------------------------------------------------*\
									expander
\* -----------------------------------------------------------------------*/

int			check_last_expansion_occurrence(char *token);
char		*minishell_expansion(char *token);
char		*is_envar_expansible(char *token, int *i, char **final_str);
char		*cases_that_are_not_expansible(char *token);
char		*get_env(char *aux);
void		expander(void);
void		expand_check_next_character(char *token, int *i, char **final_str);
t_bool		is_brace_expansion(char *token, int *i, char **final_str);
t_bool		is_envar_between_squote(char *token);

/* -----------------------------------------------------------------------*\
									builtins
\* -----------------------------------------------------------------------*/

int			builtin_cd(t_list *node);
int			builtin_echo(t_list *cmd_builtins, int fd_out);
int			builtin_export(t_list *node, int outfd);
int			builtin_unset(t_list *node);
int			count_quotes_pair(char	*str, char c, int *i);
int			split_count_words(char *str, char c);
int			split_count_words(char *str, char c);
char		**split_assign_values(char *str, char c, int count);
void		builtin_env(int outfd);
void		builtin_pwd(int outfd);
void		builtin_exit(t_list *node, int outfd);
void		create_env(char **envp);
void		ft_lstdelone_array(t_list **lst);
void		ft_lstclear_array(t_list **lst);
void		execute_builtins(t_list *node, int outfd);
void		msg_error_not_a_valid_identifier(char *token, char *cmd);
void		bash_change_colors(t_list *node);
void		cmd_clear(void);
t_bool		is_builtins(t_list *node);
t_bool		unset_error_identifier(char **next, t_list **node, char *cmd);
t_bool		error_invalid_identifier(char **next, t_list **node, char *cmd);
t_bool		check_error_invalid_identifier(char *token);
t_bool		check_unset_chr_valid_name(char *token);

/* -----------------------------------------------------------------------*\
									COMMANDS
\* -----------------------------------------------------------------------*/

int			count_id_token_before_pipe(int id, t_list *node);
int			count_id_token(int id);
int			count_tokens_before_pipe(t_list *node);
void		get_cmd_data(void);
void		get_argv(t_commands *cmd, t_list *node);
void		get_linked_list_builtins(t_commands *cmd);
void		get_linked_list_argv(t_commands *cmd);
void		get_files_redirectors(t_commands *cmd, int *ifd, int *ofd);
void		open_files(t_arguments *args, int *ifd, int *ofd, t_commands *cmd);
void		check_redirectors(t_commands *cmd, int id_token);
void		open_infile(char *file_tks, int flags, int *outfd, t_bool *error);
void		open_outfile(char *file_tks, int flags, int *outfd, t_bool *error);
void		msg_error_open_file(char *token, t_bool *error);
void		msg_error_heredoc(void);
void		create_heredoc(char *delimiter, t_bool *error);
void		destroy_heredoc(void);
void		get_cmds(t_commands *cmd, t_list *node);
void		get_envp(t_commands *cmd);
void		get_envp_path(t_commands *cmd);
void		init_fd_data(t_commands *cmd);
t_bool		get_path(t_commands *cmd);
t_bool		is_cmd_executable(t_commands *cmd);
t_bool		check_path(t_commands *cmd, t_list *node);

/* -----------------------------------------------------------------------*\
									executer
\* -----------------------------------------------------------------------*/

void		fd_memory_allocate(void);
void		child_dup_redirection(t_list *node, int i);
void		child_process_check(t_list *node, int i);
void		child_process_execution(t_list *node);
void		close_pipes(void);
void		msg_error_cmd_not_found(int status, char *cmd);
void		executer(void);
void		fork_check(int i);
void		forking(void);
void		free_cmd_data(void);
void		destroy_t_commands(void *cmds);
void		dup_redirection(t_list *node);
void		init_data_executer(void);
void		init_pipe_values(void);
void		wait_status(void);
void		add_free_me(char **content);
void		close_fds(void);
t_list		*ft_lstnew_free_me(void *content);

#endif
