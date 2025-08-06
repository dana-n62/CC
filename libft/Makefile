CC = cc
FLAGS = -Werror -Wall -Wextra #to include the .h file
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_isascii.c ft_strchr.c \
ft_isprint.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c \
ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
ft_strdup.c ft_calloc.c ft_toupper.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c \
ft_itoa.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS) libft.h
	$(CC) $(FLAGS) -c  $(SRCS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
