CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux-master
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lmlx

LIBFT_DIR = lib_ft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line

SRCS = main.c free_game.c read_map.c moving.c map.c map_checks.c images.c mouse_handeling.c\
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all:$(NAME)
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c header.h $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
