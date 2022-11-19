NAME 			= minishell

LIBFT        	= libft/libft.a
LIBFTDIR     	= libft/

SRCDIR  		= src/
OBJDIR  		= obj/
INCDIR  		= include/

BIN				= bin/minishell

LIBFLAGS 		= -lft
LIBREADLINE		= -lreadline
#CFLAGS			= -Wall -Werror -Wextra
CFLAGS 			+= -g -I ${LIBFTDIR} -I ${INCDIR}

CC 				= cc


FILES   		=	main.c				\
					error_handling.c	\
					prompt.c			\
					tokens.c

SRC 			= ${addprefix ${SRCDIR}, ${FILES}}
OBJ 			= ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

REQUIRED_DIRS	= ${sort ${dir ${OBJ}}} bin/

all: ${NAME}

print:
	echo ${REQUIRED_DIRS}

${REQUIRED_DIRS}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${REQUIRED_DIRS} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} ${LIBFLAGS} -o ${BIN} ${LIBREADLINE}
	@cp ${BIN} ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${LIBFT}:
	@make -C ${LIBFTDIR}
	@make bonus -C ${LIBFTDIR}

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@rm -rf ${OBJDIR}
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${BIN}
	rm -rf ${LIBFT}

re: fclean all

test:
	@clear
	@make
	@./minishell

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m