#include "minishell.h"

void    free_ptrs(char **str)
{
    int    i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

void	handle_quoting(char *list, int original_value, int replaced_value)
{
	size_t	i;
	char	*aux;
    int     quotes;

	i = 0;
	aux = list;
    quotes = 0;
	while (aux[i])
	{
        if (aux[i] == SQUOTE)
            quotes = !quotes;
		if (aux[i] == original_value && !quotes)
			aux[i] = replaced_value;
		i++;
	}
}


//TODO
/*1) Adicionar espaços antes e depois de cada operador encontrado, porque, em caso
de aspas não fechadas, a split precisa funcionar na divisão dos espaços encontrados.*/

int	token_count()

void	add_spaces()
{
	token_count(); //retorna número de tokens

}

void    tokens(int argc, char **argv)
{
    char    *arguments;
    char    **tokens;
    int     i;

    arguments = ft_strdup(".gitignore < tr ex ' X | tr pi 'P ' > outfile");
    i = 0;

	add_spaces(arguments);
	handle_quoting(arguments, SPACE, TEMP);
    tokens = ft_split(arguments, TEMP);
    while (tokens[i])
    {
        printf("%d) tokens[%d] = %s\n", i, i, tokens[i]);
        i++;
    }
    free_ptrs(tokens);
    free(arguments);
}


























