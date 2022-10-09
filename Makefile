# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arupert <arupert@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:38:49 by arupert           #+#    #+#              #
#    Updated: 2022/01/04 17:59:55 by arupert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= libftprintf.a

SRC_FILES	= ft_printf.c \
			  ft_printf_char.c \
			  ft_printf_hex.c \
			  ft_printf_int.c \

OBJS		= $(SRC_FILES:.c=.o)

HEADER		= ft_printf.h

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

.PHONY:		all clean fclean re

%.o:		%.c $(HEADER)
			$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	ar -rc $(LIB) $?
	ranlib $(LIB)

bonus:		$(NAME)

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(LIB)

re:			fclean all
