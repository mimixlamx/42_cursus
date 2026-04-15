NAME 		= pipex

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

LIBFT_DIR	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = pipex.c \
	fd.c \
	free.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all:  $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
