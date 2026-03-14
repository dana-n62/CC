CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = ../minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lmlx

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ../GNL

SRCS = main.c map_parsing.c map_validation.c path_validation.c\
	graphics.c event_handler.c movement.c free_functions.c\
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
