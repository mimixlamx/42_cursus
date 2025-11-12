NAME	= libftprintf.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC	= ft_printf.c \
	ft_putnbrbase.c \
	ft_putnbr.c \
	ft_putunsigned.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putvoidptr.c

OBJ_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
