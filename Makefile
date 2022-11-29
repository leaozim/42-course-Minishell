NAME			=	minishell

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

OBJ_DIR			=	./obj
OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH		=	./include
HEADER_FILES	=	defines.h minishell.h printf_colors.h

SRC				=	main.c				\
					error_handling.c	\
					utils.c				\
					init_minishell.c	\
					$(PROMPT) $(LEXER) $(EXPANDER)

PROMPT			=	prompt.c

LEXER			=	tokens.c			\
					handle_spaces.c		\
					create_token_list.c	\
					utils_lexer.c

EXPANDER		=	expander.c

DIRS			=	. lexer prompt expander
IFLAGS			=	-I $(HEADER_PATH)
LDFLAGS			=	-L$(LIBFT_PATH) -lft
CFLAGS			=	-Wall -Wextra -Werror

VPATH			=	$(addprefix ./src/, $(DIRS))
VPATH			+=	$(HEADER_PATH)

CFLAGS			+=	-g3 

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

$(NAME): $(LIBFT)  $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

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
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp -s ./minishell

mc:	all
	clear
	./minishell

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY:	all clean fclean re git test
