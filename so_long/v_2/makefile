CC = cc
CFLAGS = -Werror -Wall -Wextra -g

NAME = so_long

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

GNLDIR = ./GNL

MLXDIR = ./minilibx-linux
MLXFLAGS = -L$(MLXDIR) -lmlx_Linux -lX11 -lXext -lmlx
MLX = $(MLXDIR)/libmlx.a

SRCS = main.c read_map.c \
	$(GNLDIR)/get_next_line.c $(GNLDIR)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJS): $(SRCS) header.h $(GNLDIR)/get_next_line.h
	$(CC) $(CFLAGS) -I$(GNLDIR) -c $< -o $@
$(MLX):
	make -C $(MLXDIR)
$(LIBFT):
	make -C $(LIBFTDIR)
clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean
	rm -f $(OBJS)
fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
