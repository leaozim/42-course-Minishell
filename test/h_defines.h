#ifndef H_DEFINES_H
# define H_DEFINES_H

# define TOKENS_GENERAL_1 "ls -la .."
# define TOKENS_GENERAL_2 "ls -la .. | cat -e | wc -l"
# define TOKENS_GENERAL_3 "export MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minishell"
# define TOKENS_SQUOTE_1 "infile   < tr a '   ' |   tr ' ' x > outfile"
# define TOKENS_SQUOTE_2 ".gitignore < tr ex ' X' | tr pi 'P ' > outfile"
# define TOKENS_SQUOTE_3 "echo<' oi  '?$p' humano  | '|>>"
# define TOKENS_DQUOTES "infile   < tr a \"   \" |   tr \" \" x > outfile"
# define TOKENS_MIXED_QUOTES "infile   < tr a \"   \" |   tr \' \' x > outfile"
# define TOKENS_PARALLEL_QUOTES_1 "infile   < tr a \"   \' |   tr \' \" x > outfile"
# define TOKENS_PARALLEL_QUOTES_2 "infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile"
# define TOKENS_DETACHED_QUOTE_1 "inf'ile"
# define TOKENS_DETACHED_QUOTE_2 "inf\"ile"
# define TOKENS_DETACHED_QUOTE_3 "infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile"

# define TOKENS_PIPE_1 "help| rg unset"
# define TOKENS_PIPE_2 "help|rg unset"
# define TOKENS_GREATERTHAN_1 "ls> out"
# define TOKENS_GREATERTHAN_2 "ls>out"
# define TOKENS_LESSTHAN_1 "out<rg ."
# define TOKENS_LESSTHAN_2 "cat<out"
# define TOKENS_LESSTHAN_3 "<cat out"
# define TOKENS_LESSTHAN_4 "<out rg '.'"
# define TOKENS_DOUBLE_GREATERTHAN "rg a>>out"
# define TOKENS_DOUBLE_LESSTHAN_1 "<<. cat"
# define TOKENS_DOUBLE_LESSTHAN_2 "cat<<."

#endif