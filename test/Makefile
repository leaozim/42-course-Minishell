NAME	= minishell_test

HEADER	= $(shell ls . unity | grep .h$)
# HEADER	+= ./src/test.h

SRCS	= $(shell ls . unity | grep .c$)

# MINISHELL_OBJS		= $(shell find ../obj -type f | grep .o$ | grep -v main)

LIBFT_PATH	= ../libft
LIBFT 	= $(LIBFT_PATH)/libft.a

# MINILIBX_PATH	= ../libs/minilibx
# MINILIBX		= $(MINILIBX_PATH)/libmlx.a

MINISHELL_OBJS = $(shell find ../obj -type f | grep .o$ | grep -v main)

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINISHELL_OBJS)

CFLAGS	= -Wall -Wextra -g3
IFLAGS	= -I. -Iunity -I../include
# LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

VPATH	= unity

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(NAME): $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:	all clean fclean re run