CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -g3

NAME = yakuza

SRC_DIR = srcs
SRC_FILES = main colors events init_mlx 
INC_DIR = include

SRCS =  $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC_FILES))) 
OBJCS = $(SRCS:.c=.o)

# ---------------- LIBFT ----------------
DIR_LIB = ./libft
LIBFT = $(DIR_LIB)/libft.a

# ---------------- MLX42 ----------------
DIR_MLX = ./MLX42
MLX_LIB = $(DIR_MLX)/build/libmlx42.a
MLX_INC = -I$(DIR_MLX)/include
MLX_FLAGS = -L/usr/local/lib -ldl -lglfw -pthread -lm
# MLX_FLAGS = -ldl -lglfw -pthread -lm


# ---------------- RULES ----------------
all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJCS) $(LIBFT) $(MLX_LIB) include/yakuza.h
	$(CC) $(CFLAGS) $(OBJCS) -o $(NAME) -I$(DIR_LIB) $(MLX_INC) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS)

# 	$(CC) $(CFLAGS) $(OBJCS) $(LIBFT) $(MLX_LIB) -o $(NAME) -I$(DIR_LIB) $(MLX_INC) $(MLX_FLAGS)

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
