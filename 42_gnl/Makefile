NAME	= get_next_line.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC	=	ft_get_next_line.c \
		ft_get_next_line_utils.c
OBJ_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c ft_get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
