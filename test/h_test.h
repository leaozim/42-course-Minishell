#ifndef H_TEST_H
# define H_TEST_H

# include "unity/unity.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include "../include/minishell.h"

/*
Functions to be tested
*/

void	test_check_spaces(void);
void	test_check_valid_quoting(void);
void	test_check_program(void);

//The specific characters: < > | ' " >> <<
void	check_token_qtt(void);
void	check_token_count(void);
void	check_token_count_quotes(void);
void	check_token_count_redirection(void);

#endif
