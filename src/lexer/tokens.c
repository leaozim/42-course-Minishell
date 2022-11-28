#include "../../include/minishell.h"

void	count_tokens_specific(char *str, int qtt_tokens)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
			get_quotes(value, str[i], &i, &qtt_tokens);
		else if (str[i] == PIPE || str[i] == RDRCT_OU || str[i] == RDRCT_IN)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN && str[i + 1] == RDRCT_IN)
		{
			qtt_tokens += 1;
			i++;
		}
		else if (str[i] == RDRCT_OU && str[i + 1] == RDRCT_OU)
		{
			qtt_tokens += 1;
			i++;
		}
		i++;
	}
}

int	*identify_tokens(char **str, int len_tab)
{
	int		i;
	int		*id_tks;
	char	*aux;

	i = 0;
	id_tks = ft_calloc(len_tab, sizeof(int));
	while (i < len_tab)
	{
		aux = str[i];
		if (aux[0] == DQUOTES || aux[0] == SQUOTE)
			id_tks[i] = aux[0];
		else if (ft_strlen(aux) == 1)
			id_tks[i] = aux[0];
		else if (aux[0] == RDRCT_IN && ft_strlen(aux) == 2)
			id_tks[i] = HEREDOC;
		else if (aux[0] == RDRCT_OU && ft_strlen(aux) == 2)
			id_tks[i] = APPEND;
		else
			id_tks[i] = COMMAND;
		i++;
	}
	return (id_tks);
}

void	creat_tokens(t_minishell *ms, t_tokens *tokens)
{
	char	*str_with_spcs;
	int		len_tab_tokens;

	(void)tokens;
	replace_value_inside_quotes(ms->prompt_line, SPACE, 48);
	count_tokens_specific(ms->prompt_line, ms->qtt_tokens);
	str_with_spcs = add_spaces_specific_tokens(ms->prompt_line, ms->qtt_tokens);
	ms->tab_tokens = ft_split(str_with_spcs, ' ');
	len_tab_tokens = check_len_tab(ms->tab_tokens);
	ms->tab_id = identify_tokens(ms->tab_tokens, len_tab_tokens);
	create_token_list(ms, ms->tab_tokens, ms->tab_id, len_tab_tokens);
	free(str_with_spcs);
}
