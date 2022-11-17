/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:31:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/17 13:34:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//*argv + 2 é uma aritmética de ponteiro para pular o "./" do executável
void    check_program_name(char **argv)
{
    if (!ft_strncmp(*argv + 2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME)) == 0)
    {
        printf("Command '%s' not found, did you mean:\n  command '%s' from %s %s?\n",
        (*argv + 2), PROGRAM_NAME, AUTHORS_NAME, AUTHORS_GROUP);
        exit(COMMAND_NOT_FOUND);
    }
}
