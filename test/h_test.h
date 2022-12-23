#ifndef H_TEST_H
# define H_TEST_H

# include "unity/unity.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include "../include/minishell.h"
# include "h_defines.h"
# include "../libft/libft.h"

/*
Functions to be tested
*/

void		test_save_spaces_between_quotes(void);
void		test_check_valid_quoting(void);
void		test_check_program(void);
void		test_check_replace_value_inside_quotes(void);

//The specific characters: < > | ' " >> <<
void		check_token_qtt(void);
void		test_save_spaces(void);
void		check_token_count(void);
void		check_token_count_quotes(void);
void		check_token_count_redirection(void);

void		test_add_spaces(void);
void		test_valid_add_spaces(void);
void		check_identify_tokens(void);
void		check_qtt_tokens(void);
void		check_repl(void);

//EXPANDER
void		check_expander_count_dollar_sign(void);
void		check_expander(void);
void		check_brace_expansion(void);

void		test_error_syntax_consecutive_metachacacter(void);
void		test_is_error_syntax_metachacacter(void);
void		test_error_syntax_single_metachacacter(void);
void		free_ms(void);
void		test_is_error_syntax_metachacacter(void);
void		test_error_syntax_single_metachacacter(void);
void		test_open_files(void);
void        test_builtin_export(void);

#endif
