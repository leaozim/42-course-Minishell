#include "../../include/minishell.h"

char *expander(char *token)
{
	char *envar;
	char *ptr;

	if (!token)
		return (NULL);
	envar = token;
	envar++;
	if ((ptr = getenv(envar)) == NULL)
		return (NULL);
	return (ptr);
}


// int main(int argc, char **argv, char **envp)
// {
// 	char *ptr;

// 	ptr = getenv("NAM");
// 	printf("%p\n", ptr);
// }
