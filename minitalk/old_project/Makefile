CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = minitalk
CLIENT = client
SERVER = server
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o server
$(CLIENT):
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o client

clean :
	rm -f server
	rm -f client
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
