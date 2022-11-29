#include "../../include/minishell.h"

char	*expander(char *token)
{
	char	*envar;
	char	*ptr;

	if (!token)
		return (NULL);
	envar = token;
	envar++;
	ptr = getenv(envar);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
