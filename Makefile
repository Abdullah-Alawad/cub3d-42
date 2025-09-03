# CC = cc 
# CFLAGS = -Wall -Wextra -Werror -g3 

# SRCS = main.c events.c
# OBJCS = $(SRCS:.c=.o)


# NAME = yakuza

# DIR_LIB = ./libft
# LIBFT = $(DIR_LIB)/libft.a


# DIR_MLX = ./MLX42
# MLX = $(DIR_MLX)/libmlx.a
# MLX_INC = I$(DIR_MLX)/include
# MLX_FLAGS = L$(DIR_MLX) -lmlx -lX11 -lXext -lm 


# all: $(LIBFT) $(MLX) $(NAME)

# $(NAME): $(OBJCS) $(LIBFT) $(MLX) yakuza.h
# 	$(CC) $(CFLAGS) $(OBJCS) -L$(DIR_LIB) -lft $(MLX_FLAGS) -o $(NAME) -I$(DIR_LIB) $(MLX_INC)

# $(LIBFT):
# 	make -C $(DIR_LIB) 

# $(MLX):
# 	make -C $(DIR_MLX)

# re: fclean all
# clean:
# 	make clean -C $(DIR_LIB)
# # 	make clean -C $(DIR_MLX)
# 	rm -f $(OBJCS)

# fclean: clean
# 	make fclean -C $(DIR_LIB)
# # 	make fclean -C $(DIR_MLX)
# 	rm -f $(NAME)
# .PHONY: all re clean fclean


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c events.c
OBJCS = $(SRCS:.c=.o)

NAME = yakuza

# ---------------- LIBFT ----------------
DIR_LIB = ./libft
LIBFT = $(DIR_LIB)/libft.a

# ---------------- MLX42 ----------------
DIR_MLX = ./MLX42
MLX_LIB = $(DIR_MLX)/build/libmlx42.a
MLX_INC = -I$(DIR_MLX)/include
MLX_FLAGS = -ldl -lglfw -pthread -lm

# ---------------- RULES ----------------
all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJCS) $(LIBFT) $(MLX_LIB) yakuza.h
	$(CC) $(CFLAGS) $(OBJCS) $(LIBFT) $(MLX_LIB) -o $(NAME) -I$(DIR_LIB) $(MLX_INC) $(MLX_FLAGS)

$(LIBFT):
	make -C $(DIR_LIB)

# Build MLX42 once with CMake
$(MLX_LIB):
	cd $(DIR_MLX) && cmake -B build && cmake --build build -j4

re: fclean all

clean:
	make clean -C $(DIR_LIB)
	rm -f $(OBJCS)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -f $(NAME)

.PHONY: all re clean fclean
