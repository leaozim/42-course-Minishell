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

void	get_quotes(int value, char line, int *i, int **qtt_tokens)
{
	(void)qtt_tokens;
	value = line;
		*i += 1;
	while (line && line != value)
		*i += 1;
	// if (line[*i] == value)
	// 	**qtt_tokens += 1;
}

void	reverse_replace(char **table_tokens, int len_tab)
{
	int i = -1;
	while(len_tab > ++i)
		replace_value_inside_quotes(table_tokens[i], REPLACE_VALUE, SPACE);
}