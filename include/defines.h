#ifndef DEFINES_H
# define DEFINES_H

# define TEMP_VALUE -1

# define ARGUMENT_LIST_TOO_LONG 7
# define COMMAND_NOT_FOUND 127


typedef struct s_data
{
    char *token_list;
}               t_data;

# define PROMPT "MiniHELL $"
# define TOKEN_COUNT 17
# define TEMP 2
# define SPACE ' '

enum e_tokens
{
    COMMAND = 1,
    DQUOTES = '"',
    DOLLAR_SIGN = '$',
    SQUOTE = '\'',
    SEMICOLON = ';',
    LESSTHAN = '<',
    GREATERTHAN = '>',
    PIPE = '|',
    QUERY = '?',
};


typedef enum e_boolean
{
    FALSE,
    TRUE,
}    t_boolean;

#endif
