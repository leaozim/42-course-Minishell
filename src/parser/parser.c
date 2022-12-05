#include "../../include/minishell.h"

t_bool    is_metacharacters(int id_tks)
{
	if (id_tks == HEREDOC ||
		id_tks == APPEND ||
		id_tks == RDRCT_IN ||
		id_tks == RDRCT_OU ||
		id_tks == PIPE)
		return (TRUE);
	return (FALSE);
}

void    parser(t_minishell *ms)
{
	t_list		*no;
	t_tokens	*tokens;
	t_tokens    *next_tokens;

	no = ms->tks;
	while (no)
	{
		tokens = (t_tokens *)no->content;
		if (is_metacharacters(tokens->id_tks) && tokens->id_tks != PIPE)
		{
			if (no->next && is_metacharacters(((t_tokens *)no->next->content)->id_tks))
			{
				ft_putstr_fd("Invalid syntax\n", STDERR_FILENO);
				return ;
			}
			next_tokens = (t_tokens *)no->next->content;
			if (tokens->id_tks == HEREDOC)
				next_tokens->id_tks = DELIMITER;
			if (tokens->id_tks == APPEND)
				next_tokens->id_tks = FILE_APPEND;
			if (tokens->id_tks == RDRCT_IN)
				next_tokens->id_tks = FILE_IN;
			if (tokens->id_tks == RDRCT_OU)
				next_tokens->id_tks = FILE_OUT;
			else
				next_tokens->id_tks = COMMAND;		
		}			   
		no = no->next;
	}
}


