CC= cc
CFLAGS= -Werror -Wall -Wextra -g
NAME= libftprintf.a
SRCS= ft_printf.c print_char.c print_str.c print_number.c print_unsigned.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all
.PHONY: all clean fclean re
