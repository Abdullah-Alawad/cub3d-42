/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:53:36 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 11:17:09 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YAKUZA_H
# define YAKUZA_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 1900
# define HEIGHT 1000

# define MINI_WIDTH 380
# define MINI_HEIGHT 200

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_news_tex
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}					t_news_tex;

typedef struct s_draw_ints
{
	int				tex_x;
	int				tex_y;
	int				d;
	int				line_height;
}					t_draw_ints;

typedef struct s_wall_path
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
}					t_wall_path;

typedef struct s_minimap
{
	float			h;
	float			w;
	mlx_image_t		*miniimg;
}					t_minimap;

typedef struct s_coords
{
	double			w;
	double			h;
}					t_coords;

typedef struct s_ints
{
	int				w;
	int				h;
}					t_ints;

typedef struct s_camera
{
	double			camerax;
	double			ray_dirx;
	double			ray_diry;
	int				mapx;
	int				mapy;
	double			delta_disx;
	double			delta_disy;
	int				stepx;
	int				stepy;
	double			side_disx;
	double			side_disy;
	int				side;
	int				wall_starts;
	int				wall_ends;
	double			player_to_wall_dis;
}					t_camera;

typedef struct s_kumicho
{
	t_coords		offset;
	t_coords		direction;
	t_coords		plane;
	char			dir;
}					t_kumicho;

typedef struct s_map
{
	int				height;
	int				width;
	int				player_count;
	char			player_direction;
	char			**map;
	char			**cpy_map;
	int				px;
	int				py;
	t_rgb			*floor;
	t_rgb			*ceiling;
	t_wall_path		*wall;
}					t_map;

typedef struct s_tokugawa_sokoku
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_minimap		*minimap;
	t_map			*map;
	t_camera		*camera;
	t_kumicho		*kumicho;
	t_news_tex		*texture;
}					t_tokugawa_sokoku;

// utils.c
void				side_dis(t_tokugawa_sokoku **yakuza);
void				dis_to_wall(t_tokugawa_sokoku **yakuza);
void				init_texture(t_tokugawa_sokoku **yakuza);
void				setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac);
void				allocate_map(t_map **map);

// tokogawa_sokoku.c
void				enter_tokugawa_sokoku(void *land);

// parsing.c
int					parsing_reading(int ac, char **av, t_map **map);

// parsing_utils.c
int					is_direction(char *buf);
int					is_floor_cieling(char *buf);
int					is_map(char *buf);
void				check_line(t_map **map, char *line);

// movements.c
void				forward(t_tokugawa_sokoku *yakuza);
void				backward(t_tokugawa_sokoku *yakuza);
void				left(t_tokugawa_sokoku *yakuza);
void				right(t_tokugawa_sokoku *yakuza);

// minimap.c
void				minimap(t_minimap *minimap, t_map *map);
void				draw_background(t_minimap *minimap);
void				frees(char *s1, char *s2);

// map_validation_check.c
int					is_map_valid(char *buf);
int					is_path_valid(char *buf);
int					is_colors_checker(char **comb, t_rgb **draw);
int					is_path_valid(char *buf);

// map_validation_check_2.c
void				map_check(char **map, int height);

// init_tokugawa.c
void				init_tokugawa_sokoku(t_tokugawa_sokoku **yakuza);
void				init_minimap(t_tokugawa_sokoku **yakuza);
void				init_kumicho(t_tokugawa_sokoku **yakuza);
void				init_camera(t_tokugawa_sokoku **yakuza, int x);

// init_map.c
void				get_width_buf(char *buf, t_map **map, char **map_buf);
void				set_color(char *buf, t_map **map);
int					setting_map(t_map **map, char **av, int ac);
void				init_map_buf(char **map_buf);

// init_kumcho
void				init_kumicho_2(t_tokugawa_sokoku **yakuza);
void				minimap_color(t_map *map, int h, int w, uint32_t *color);

// flood_fill.c
void				copy_map(t_map **map);
int					flood_fill(t_map *map, int py, int px);
void				save_player_positions(t_map **map);
int					open_map(int *fd, char **av, int ac);

// events.c
void				keypress_hook(mlx_key_data_t keycode, void *param);
void				close_win(void *param);
void				handle_keys(mlx_key_data_t keycode,
						t_tokugawa_sokoku *yakuza);
void				rotate_left(t_tokugawa_sokoku *yakuza,
						double rotation_speed);
void				rotate_right(t_tokugawa_sokoku *yakuza,
						double rotation_speed);

// error_handling.c
void				malloc_err(void);
void				free_double_array(char **doub);
void				free_map(t_map *map);
void				free_struct(t_tokugawa_sokoku *yakuza);
void				invalid_path(char *str);

// // colors.c
uint32_t			rgb(int r, int g, int b);
void				color_it(mlx_image_t *img, t_rgb *draw, char fc);
void				set_ceiling_floor(t_tokugawa_sokoku **yakuza);
void				draw_wall_column_2(t_tokugawa_sokoku *yakuza,
						mlx_texture_t *tex, int x, t_draw_ints draw_ints);
#endif