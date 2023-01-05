NAME				=	minishell

LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

OBJ_DIR				=	./obj
OBJS				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH			=	./include
HEADER_FILES		=	defines.h minishell.h printf_colors.h

SRC					=	main.c										\
						error_handling.c							\
						destroyers.c								\
						init_minishell.c							\
						signals.c									\
						change_colors.c								\
						cmd_clear.c									\
						$(PROMPT) $(LEXER) $(EXPANDER) $(PARSER)	\
						$(BUILTINS) $(EXECUTER)

PROMPT				=	prompt.c

LEXER				=	tokens.c									\
						handle_spaces.c								\
						create_token_list.c							\
						utils_lexer.c								\
						join_tokens.c

EXPANDER			=	expander.c									\
						brace_expansion.c							\
						expander_checks.c							\

PARSER 				=	parser.c 									\
						handle_metachars.c							\
						open_files.c 								\
						heredoc.c									\
						error_parser.c								\
						handle_quotes.c

BUILTINS			=	echo.c										\
						is_builtins.c								\
						env.c										\
						export.c									\
						pwd.c										\
						cd.c										\
						export_handle_errors.c						\
						unset.c

EXECUTER			=	executer.c

DIRS				=	. lexer prompt expander parser builtins executer
IFLAGS				=	-I $(HEADER_PATH)
LDFLAGS				=	-L$(LIBFT_PATH) -lft
CFLAGS				=	-Wall -Wextra -Werror

VPATH				=	$(addprefix ./src/, $(DIRS))
VPATH				+=	$(HEADER_PATH)

CFLAGS				+=	-g

WHITE				=	\e[00m
GREEN				=	\e[32m
RED					=	\e[91m
YELLOW				=	\e[033m
BLUE				=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)
	make clean -C test

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C test

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)
	make bonus -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lreadline
#@echo "$(GREEN)MINISHELL compiled succesfully$(WHITE)"

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
#@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
#$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))


$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

test:	all
	make run -C test

test_vall:	all
	make val -C test

val: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --trace-children-skip='*/bin/*,*/sbin/*' --suppressions=readline.supp ./minishell

mc:	all
	clear
	./minishell

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY:	all clean fclean re git test