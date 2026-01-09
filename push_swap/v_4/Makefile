CC = cc
CFLAGS = -Werror -Wall -Wextra -g
NAME = push_swap
SRCS = push_swap.c nodes.c input_checker.c sorting_data.c \
	ft_rotate.c ft_reverse_rotate.c ft_swap.c ft_push.c \
	stack_builder.c turk_algorithm.c turk_algorithm_core.c turk_helper_functions.c \
	find_functions.c assigning_functions.c
OBJS = $(SRCS:.c=.o)
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -I$(LIBFTDIR) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	-rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	-rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
