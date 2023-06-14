NAME = btc

SRC = main.cpp BitcoinExchange.cpp

CC = c++ -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

OBJS = $(OBJ)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)


clean : 
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all