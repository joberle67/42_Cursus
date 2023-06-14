# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joberle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:37:49 by joberle           #+#    #+#              #
#    Updated: 2022/03/21 13:37:55 by joberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SUBDIR	= src/

SRCS	= $(SUBDIR)ft_printf.c \
			$(SUBDIR)ft_pourcent.c \
			$(SUBDIR)ft_putchar.c \
			$(SUBDIR)ft_putptr.c \
			$(SUBDIR)ft_printnbr.c \
			$(SUBDIR)ft_printunsigned.c \
			$(SUBDIR)ft_printhex.c \
			$(SUBDIR)ft2_strlen.c \
			$(SUBDIR)ft2_itoa.c \

OFILE	= ft_printf.o \
			ft_pourcent.o \
			ft_putchar.o \
			ft_putptr.o \
			ft_printnbr.o \
			ft_printunsigned.o \
			ft_printhex.o \
			ft2_strlen.o \
			ft2_itoa.o \
		

OBJS	= $(SRCS:%.c=%.o)
FLAGS	= -Wall -Werror -Wextra

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I./
		ar rc $(NAME) $(OFILE)

all: $(NAME)

clean:
		rm -f $(OFILE)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
