#ifndef TEST_H
# define TEST_H

# include <unity.h>
# include <unity_internals.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// # include "../../include/minishell.h"
# include "minishell.h"

/*
Functions to be tested
*/

void    test_lexer(void);
void    test_check_program(void);

#endif