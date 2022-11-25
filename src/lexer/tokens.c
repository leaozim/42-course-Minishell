#include "../../include/minishell.h"

int	count_tokens_specific(char *str)
{
	int	i;
	int	value;
	int	qtt_tokens;

	i = 0;
	value = 0;
	qtt_tokens = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			value = str[i];
			i++;
			while (str[i] && str[i] != value)
				i++;
			if (str[i] == value)
				qtt_tokens += 1;
		}
		else if (str[i] == PIPE)
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
		else if (str[i] == RDRCT_OU)
			qtt_tokens += 1;
		else if (str[i] == RDRCT_IN)
		{
			qtt_tokens += 1;
		}
		i++;
	}
	return (qtt_tokens);
}

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
			id_tks[i] = 5;
		i++;
	}
	return (id_tks);
}

// t_tokens	*creat_content(char *tks, int index)
// {
// 	t_tokens	*content;

// 	content = ft_calloc(1, sizeof(t_tokens));
// 	content->tokens = tks;
// 	content->id_tks = index;
// 	return (content);
// }

// void	add_argumm_in_stack(t_minishell *ps, char *str, int *index)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < ps->size_list)
// 		ft_lstadd_back(&ps->a, \
// 		ft_lstnew(creat_content(ps->value[i], ps->index[i])));
// }

// void	create_linked_list(t_minishell ms, char **tokens, int *id_tokens)
// {

// }

void	creat_tokens(t_minishell *ms, t_tokens *tokens)
{
	char	**tab_tokens;
	int		*tab_id;
	char	*str_with_spcs;
	int		qtt_tokens;
	int		len_tab_tokens;

	(void)tokens;
	replace_value_inside_quotes(ms->prompt_line, SPACE, 48);
	qtt_tokens = count_tokens_specific(ms->prompt_line);
	str_with_spcs = add_spaces_specific_tokens(ms->prompt_line, qtt_tokens);
	tab_tokens = ft_split(str_with_spcs, ' ');
	len_tab_tokens = check_len_tab(tab_tokens);
	tab_id = identify_tokens(tab_tokens, len_tab_tokens);
	// create_linked_list(ms, tab_tokens, tab_id);

	free_ptrs(tab_tokens);
	free(tab_id);
	free(str_with_spcs);
}
