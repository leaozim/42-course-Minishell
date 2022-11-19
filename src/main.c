/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:41:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/19 17:18:57 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
	
int	main(int argc, char **argv, char **envp)
{
	check_program(argc);
	while (1)
	{
		creat_prompt();
	}
	return (EXIT_SUCCESS);
}
