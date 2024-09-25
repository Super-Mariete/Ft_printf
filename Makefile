# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 21:32:36 by made-ped          #+#    #+#              #
#    Updated: 2024/09/25 22:02:17 by made-ped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c\

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

.PHONY : clean all fclean re
