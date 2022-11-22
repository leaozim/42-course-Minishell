NAME	= minishell_test

HEADER	= $(shell ls . unity | grep .h$)

SRCS	= $(shell ls . unity | grep .c$)

LIBFT_PATH	= ../libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINISHELL_PATH = ../
MINISHELL = $(MINISHELL_PATH)/minishell.a

MINISHELL_OBJS = $(shell find ../obj -type f | grep .o$ | grep -v main)

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINISHELL_OBJS)

CFLAGS	= -Wall -Wextra -g3
IFLAGS	= -I. -Iunity -I../include -I../libft
VPATH	= unity
LDFLAGS	= -L$(LIBFT_PATH) -lft

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINISHELL):
	make -C $(MINISHELL_PATH)

$(NAME): $(LIBFT) $(MINISHELL) $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	all clean fclean re run