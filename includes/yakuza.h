/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:53:36 by modat             #+#    #+#             */
/*   Updated: 2025/09/19 09:09:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YAKUZA_H
#define YAKUZA_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../includes/get_next_line.h"
# include <math.h>

#define WIDTH 1900
#define HEIGHT 900

# define MINI_WIDTH 1900/5  // norm error
# define MINI_HEIGHT 900/5	// norm error

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_wall_path
{
	char   *north;
    char   *south;
    char   *east;
    char   *west;
} t_wall_path;

typedef struct s_minimap
{
	float 	h;
	float 	w;
	mlx_image_t 	*miniimg;
	// t_kumicho	*kumicho;
} t_minimap;

typedef struct	s_coords
{
	double	w; // x
	double	h; //y
}	t_coords;

typedef struct	s_kumicho
{
	mlx_image_t *imag_minimap;
	mlx_image_t	*img; // init needed
	t_coords	offset;
	t_coords	direction;
	t_coords	plane;
	double		angle;
	char		dir;
} t_kumicho;

typedef struct s_map
{
	int 	height;
	int 	width;
	int		player_count;
	char	player_direction;
	char 			**map;
	t_rgb			*floor;
	t_rgb			*ceiling;
	t_wall_path 	*wall;
} t_map;

typedef struct s_mouse 
{
	int32_t x;
	int32_t y;
} t_mouse;

typedef struct s_tokugawa_sokoku
{
	t_minimap *minimap;
	// double h_offset;
	// double	w_offset;
	t_mouse 	*mouse;
	mlx_image_t	*img;
	t_map	*map;
	mlx_t 	*mlx;
	t_kumicho 	*kumicho;
} t_tokugawa_sokoku;

// // init_mlx.c 
// void	draw_img(mlx_t *mlx, t_rgb *draw, char fc);

// yakuza.c 
void	 setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac);
void	draw_background(t_minimap *minimap);
void 	map_drawing(t_tokugawa_sokoku *yakuza, uint32_t color, int pw, int ph);
void 	map(t_tokugawa_sokoku *yakuza);

// init_map.c
void    get_width_buf(char *buf, t_map **map, char **map_buf);
void    set_color(char *buf, t_map **map);
void 	setting_map(t_map **map, char **av, int ac);

// parsing_utils.c
int     is_direction(char *buf);
int     is_floor_cieling(char *buf);
int     is_map(char *buf);
void    check_line(t_map **map, char *line);

// parsing.c
int     parsing_reading(int ac, char **av, t_map **map);
void    allocate_map(t_map **map);

// // colors.c
uint32_t		rgb(int r, int g, int b);
void	color_it(mlx_image_t *img, t_rgb *draw, char fc);
void 	set_ceiling_floor(t_tokugawa_sokoku **yakuza);


// events.c
void	keypress_hook(mlx_key_data_t keycode, void *mlx);
void	close_win(void *mlx);
void	keys_hook(mlx_key_data_t keycode, t_tokugawa_sokoku *yakuza);
void	mouse_hook(t_mouse *xy,  t_tokugawa_sokoku *yakuza, mlx_t *mlx);

// error_handling.c
void    malloc_err(void);
void    free_arr(char **arr);
void 	exit_free(void);

// map_validation_check.c
int     is_map_valid(char *buf);
int     is_path_valid(char *buf);
void    is_colors_checker(char **comb, t_rgb **draw);

// map_validation_check_2.c
void 	map_check(char **map, int height);

// init_tokugawa.c
void 	init_tokugawa_sokoku(t_tokugawa_sokoku **yakuza);
void 	init_minimap(t_tokugawa_sokoku **yakuza);
// tokugawa_sokoku.c
void    enter_tokugawa_sokoku(void *land);

// minimap.c
void    minimap(t_minimap *minimap, t_map *map);

void print_map(t_map *m);

// movements.c
void    forward(t_tokugawa_sokoku *yakuza);
void    backward(t_tokugawa_sokoku *yakuza);
void    left(t_tokugawa_sokoku *yakuza);
void    right(t_tokugawa_sokoku *yakuza);

// rotaion.c
void    rotate_right(t_tokugawa_sokoku *yakuza, double rotation_speed);
void    rotate_left(t_tokugawa_sokoku *yakuza, double rotation_speed);

// void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
// void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param);

#endif