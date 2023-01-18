# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:02:02 by etomiyos          #+#    #+#              #
#    Updated: 2022/04/25 15:02:02 by etomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				=	libft.a
CFLAGS 				=	-Wall -Wextra -Werror -g
CC 					=	cc
LIB 				=	ar -rcs
RM					=	rm -fr
INC 				=	libft.h
SRC 				=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
						ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_memcpy.c		\
						ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c		\
						ft_memcmp.c ft_strnstr.c ft_strdup.c ft_bzero.c ft_strlcpy.c		\
						ft_strlcat.c ft_atoi.c ft_calloc.c ft_substr.c ft_strjoin.c			\
						ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c		\
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\
						ft_atof.c ft_is_num.c ft_split_count.c ft_isalpha_underscore.c		\
						ft_strrchr_pos.c ft_strcmp.c ft_strupdate.c	ft_lstnew.c				\
						ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c		\
						ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c				\
						ft_strchr_pos.c ft_strchr_count.c ft_strtrim_allchars.c				\
						ft_strtrim_specific_pos.c ft_intarray_len.c							\
						ft_free_char_array_memory.c	ft_isops.c ft_stop_chr.c ft_findsubchr.c\
						ft_lstcount_nodes.c ft_free_int_array.c ft_print_array.c			\
						ft_isspace.c ft_atoll.c ft_islong_long.c

OBJ					=	$(SRC:.c=.o)

WHITE				=	\e[00m
GREEN				=	\e[32m
RED					=	\e[91m
YELLOW				=	\e[033m
BLUE				=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))

PROGRESS			=	0

%.o: %.c
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INC)
	@$(LIB) $(NAME) $(INC) $(OBJ)
	@echo "$(GREEN)LIBFT compiled succesfully$(WHITE)"

all: $(NAME)

clean:
	@echo "$(BLUE)Removing $(WHITE)all objects"
	@${RM} $(OBJ)

fclean: clean
	@echo "$(BLUE)Removing $(WHITE)$(NAME)"
	@${RM} $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus"