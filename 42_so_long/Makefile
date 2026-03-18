NAME	= so_long.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -lX11 -Lxext

SRC	= check_map.c\
	fload_fill.c\
	free.c\
	game.c\
	move.c\
	put_images.c\
	utils_check_map.c

OBJ_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
