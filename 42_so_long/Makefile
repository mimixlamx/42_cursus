NAME 		= so_long

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g -no-pie

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_DIR	= libft 
LIBFT 		= $(LIBFT_DIR)/libft.a

MLX_DIR 	= minilibx-linux
MLX_LIB 	= $(MLX_DIR)/libmlx.a
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lXext -lX11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = check_map.c \
	free.c \
	game.c \
	move.c \
	put_images.c \
	utils_check_map.c \
	flood_fill.c 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


all:  $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) -no-pie $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

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
