# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joberle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 12:21:46 by joberle           #+#    #+#              #
#    Updated: 2022/07/05 12:24:28 by joberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

SRC =	src/stack_utils/liste_chainee.c  \
		src/stack_utils/liste_chainee_insertion.c  \
		main.c \
		src/parsing/parsing.c \
		src/parsing/parsing_utils.c \
		src/sorting/sort_big_stack.c \
		src/sorting/sort_small_stack.c \
		src/stack_utils/stack_utils.c \
		src/stack_utils/stack_utils_sorting.c \
		src/stack_utils/operations.c \
		src/sorting/sort_list_of_three.c \
		src/sorting/sort_list_of_four.c \
		src/sorting/sort_list_of_five.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
			gcc $(FLAGS) $(OBJ) libft.a libftprintf.a -o $(NAME)

clean :
			rm -rf $(OBJ)

fclean : clean
			rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
