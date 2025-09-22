/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:53:36 by modat             #+#    #+#             */
/*   Updated: 2025/09/22 15:16:44 by modat            ###   ########.fr       */
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
#define HEIGHT 1000

# define MINI_WIDTH 1900/5  // norm error
# define MINI_HEIGHT 1000/5	// norm error

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_news_tex
{
	mlx_texture_t *north;
	mlx_texture_t *south;
	mlx_texture_t *east;
	mlx_texture_t *west;
}	t_news_tex;

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

typedef struct	s_ints
{
	int	w; // x
	int	h; //y
}	t_ints;

typedef struct s_camera
{
    double camerax;
    double ray_dirx;
    double ray_diry;
	int mapx;
	int mapy;
	double delta_disx;
	double delta_disy;
	int     stepx;
	int      stepy;
	double side_disx;
	double side_disy;
    int side;
	int	wall_starts;
	int	wall_ends;
	double player_to_wall_dis;
} t_camera;

typedef struct	s_kumicho
{
	// mlx_image_t *imag_minimap;
	// mlx_image_t	*img; // init needed
	t_coords	offset;
	t_coords	direction;
	t_coords	plane;
	char		dir;
} t_kumicho;

typedef struct s_map
{
	int 	height;
	int 	width;
	int		player_count;
	char	player_direction;
	char 			**map;
	char			**cpy_map;
	int				px;
	int				py;
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
	mlx_image_t	*img;
	mlx_t 	*mlx;
	t_minimap *minimap;
	t_mouse 	*mouse;
	t_map	*map;
	t_camera *camera;
	t_kumicho 	*kumicho;
	t_news_tex	*texture;
	mlx_texture_t	*sky;
	mlx_texture_t	*grass;
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
void	init_kumicho(t_tokugawa_sokoku **yakuza);

// init_kumcho
void 	init_kumicho_2(t_tokugawa_sokoku **yakuza);

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


 void    enter_tokugawa_sokoku(void *land);
// void    init_camera(t_tokugawa_sokoku **yakuza, int x);
// void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
// void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param);

// flood_fill.c
void	copy_map(t_map **map);
int 	flood_fill(t_map *map, int py, int px);
void    save_player_positions(t_map **map);


void	print_cpy(char **map, int height);


#endif