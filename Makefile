CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(DIR_LIB) -g3

NAME = cub3D

SRC_DIR = srcs
GNL_DIR = gnl
GNL_SRCS = get_next_line 
SRC_FILES = yakuza colors parsing parsing_utils error_handling init_map \
	map_validation_check map_validation_check_2 events  minimap tokugawa_sokoku init_tokugawa \
	movements init_kumicho flood_fill utils

INC_DIR = includes

SRCS =  $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC_FILES))) \
		$(addsuffix .c, $(addprefix $(GNL_DIR)/, $(GNL_SRCS)))
OBJCS = $(SRCS:.c=.o)


DIR_LIB = ./libft
LIBFT = $(DIR_LIB)/libft.a


DIR_MLX = ./MLX42
MLX_LIB = $(DIR_MLX)/build/libmlx42.a
MLX_INC = -I$(DIR_MLX)/include
MLX_FLAGS = -L/usr/local/lib -ldl -lglfw -pthread -lm


all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJCS) $(LIBFT) $(MLX_LIB) includes/yakuza.h
	$(CC) $(CFLAGS) $(OBJCS) -o $(NAME) -I$(DIR_LIB) $(MLX_INC) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS)

$(LIBFT):
	make -C $(DIR_LIB)

$(MLX_LIB):
	cd $(DIR_MLX) && cmake -B build && cmake --build build -j4

re: fclean all

clean:
	make clean -C $(DIR_LIB)
	rm -f $(OBJCS)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(DIR_MLX)/build
	rm -f $(NAME)

.PHONY: all re clean fclean
