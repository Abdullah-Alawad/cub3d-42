CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c events.c
OBJCS = $(SRCS:.c=.o)


NAME = yakuza
DIR_LIB = ./libft
LIBFT = $(DIR_LIB)/libft.a
MLX_FLAGS = -lmlx -lX11 -lXext -lm


all: $(LIBFT) $(NAME)

$(NAME): $(OBJCS) $(LIBFT) yakuza.h
	$(CC) $(CFLAGS) $(OBJCS) -L$(DIR_LIB) -I$(DIR_LIB) -lft -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	make -C $(DIR_LIB)  # Build the libft library

re: fclean all
clean:
	make clean -C $(DIR_LIB)
	rm -f $(OBJCS)
fclean: clean
	make fclean -C $(DIR_LIB)
	rm -f $(NAME)
.PHONY: all re clean fclean
