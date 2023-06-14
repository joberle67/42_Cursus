FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_NAME = libft/libft.a printf/libftprintf.a
LIBFT = make -C ./libft
PRINTF = make -C ./printf
LIBFT_CLEAN = make clean -C ./libft
PRINTF_CLEAN = make clean -C ./printf
LIBFT_FCLEAN = make fclean -C ./libft
PRINTF_FCLEAN = make fclean -C ./printf
OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

SRC = main.c \
		src/error.c \
		src/exit_game.c \
		src/find.c \
		src/img.c \
		src/init_tab.c \
		src/move.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \

all: $(NAME)

$(NAME):$(OBJ)
	 $(LIBFT) && $(PRINTF) && $(CC) $(FLAGS) $(SRC) $(LIBFT_NAME) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	 @echo $(FONT_COLOR_GREEN)[Compilation success] $(FONT_COLOR_DEFAULT)

clean: 
		@$(RM) $(OBJ) && $(LIBFT_CLEAN) && $(PRINTF_CLEAN)
		@echo $(FONT_COLOR_RED)[OBJECT DELETED] $(FONT_COLOR_DEFAULT)

fclean: clean
		@$(RM) $(NAME) && $(LIBFT_FCLEAN) && $(PRINTF_FCLEAN)
		@echo $(FONT_COLOR_RED)[so_long DELETED] $(FONT_COLOR_DEFAULT)

re: fclean all