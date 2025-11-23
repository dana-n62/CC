CC= cc
CFLAGS= -Werror -Wall -Wextra
NAME= push_swap
SRCS= push_swap.c
OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJS) -L./libft -lft $(NAME)
clean:
	-rm -f $(OBJS)
fclean:
	-rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
