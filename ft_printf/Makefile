CC= cc
CFLAGS= -Werror -Wall -Wextra -g
NAME= libftprintf.a
SRCS=
OBJS= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
