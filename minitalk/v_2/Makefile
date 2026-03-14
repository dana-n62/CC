CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = minitalk
LIBFTDIR = ./libft
SERVER = server
CLIENT = client
SRCS_S = server.c
SRCS_C = client.c
OBJS_S = server.o
OBJS_C = client.o

all: libft $(NAME)

$(NAME): $(SERVER) $(CLIENT)
$(SERVER): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -L$(LIBFTDIR) -lft -o $(SERVER)

$(CLIENT): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -L$(LIBFTDIR) -lft -o $(CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -I. -I$(LIBFTDIR) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	-rm -f $(OBJS_S)
	-rm -f $(OBJS_C)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	-rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re libft


