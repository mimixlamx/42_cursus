NAME	= so_long.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -I/usr/include -Iminilibx-linux -O3 -c $< -o $@
SRC	= test.c

OBJ_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
