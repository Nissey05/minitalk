CLIENT_NAME = client
SERVER_NAME = server
NAME = $(CLIENT_NAME) $(SERVER_NAME)
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
OBJ = $(CLIENT_OBJ) $(SERVER_OBJ)
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L. $(LIBFT_LIB) -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L. $(LIBFT_LIB) -o $(SERVER_NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re
