NAME = libft.a
INTERN = libinternalft.a

SRC_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_split.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_atol.c
SRC_GNL = get_next_line.c get_next_line_utils.c
SRC_LISTS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstdeltop.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstset.c
SRC = $(SRC_GNL) $(SRC_LIBFT) $(SRC_LISTS)

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_LIB) script.m
	$(AR) -r $(INTERN) $(OBJ)
	ar -M < script.m
	rm -f script.m

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

script.m:
	@echo "create $(NAME)" > script.m
	@echo "addlib $(FT_PRINTF_LIB)" >> script.m
	@echo "addlib $(INTERN)" >> script.m
	@echo "save" >> script.m
	@echo "end" >> script.m

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(INTERN)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re