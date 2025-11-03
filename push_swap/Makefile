CC= cc
CFLAGS= -Werror -Wall -Wextra
NAME= push_swap
SRCS= push_swap.c ft_swap.c ft_push.c ft_rotate.c stack_status.c ft_reverse_rotate.c
OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC)$(FLAGS)$(SRCS)-o$(OBJS)
clean:
	-rm -f $(OBJS)
fclean:
	-rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
