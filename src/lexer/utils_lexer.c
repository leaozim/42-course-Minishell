#include "../../include/minishell.h"

t_bool	check_for_specific_token(char c)
{
	if (c == RDRCT_IN || \
		c == RDRCT_OU || \
		c == PIPE || \
		c == SQUOTE || \
		c == DQUOTES)
		return (TRUE);
	return (FALSE);
}

int	check_len_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_quotes(int value, char line, int *i, int *qtt_tokens)
{
	value = line[i];
		*i += 1;
	while (line[i] && line[i] != value)
		*i += 1;
	if (line[i] == value)
		*qtt_tokens += 1;
}
