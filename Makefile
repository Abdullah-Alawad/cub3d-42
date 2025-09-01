CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SRCS = yakuza.c 
OBJCS = $(SRCS:.c=.o)


NAME = yakuza
DIR_LIB = ./libft
LIBFT = $(DIR_LIB)/libft.a


all: $(LIBFT) $(NAME)

$(NAME): $(OBJCS) $(LIBFT) yakuza.h
	$(CC) $(CFLAGS) $(OBJCS) -L$(DIR_LIB) -I$(DIR_LIB) -lft -o $(NAME)

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
