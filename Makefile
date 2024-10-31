# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 21:32:36 by made-ped          #+#    #+#              #
#    Updated: 2024/10/27 14:21:16 by made-ped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_printf_utils.c\
	ft_printf_utils_number.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)
%.o:%.c
	$(CC) $(CCFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

test: testing.c
	@$(CC) -w -o test testing.c ${NAME}
	@echo "${PINK}Test compiled!${DEFCOLOR}"

.PHONY : clean all fclean re
