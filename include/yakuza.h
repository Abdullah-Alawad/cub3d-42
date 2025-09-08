/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:53:36 by modat             #+#    #+#             */
/*   Updated: 2025/09/08 20:44:01 by marvin           ###   ########.fr       */
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

#define WIDTH 1900
#define HEIGHT 900
# define ESC_KEY 65307
# define CLOSE 17

# define ZOOM_FACTOR 1.1
# define PAN_FACTOR 0.1
# define MOVE_SPEED 0.1
# define MAX_ITER 200

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define PALETTE_SIZE 16

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;



typedef struct s_wall
{
	xpm_t   *north;
    xpm_t   *south;
    xpm_t   *east;
    xpm_t   *west;
} t_wall;

typedef struct s_map
{
	int map[WIDTH][HEIGHT];
	t_rgb	*floor;
	t_rgb	*ceiling;
	t_wall 	*wall;
} t_map;

// init_mlx.c 
void	init_mlx(mlx_t    **mlx);
void	draw_img(mlx_t *mlx, t_rgb *draw, char fc);
void 	set_ceiling_floor(mlx_t *mlx, t_rgb *floor, t_rgb *ceiling);
void    init_map(t_map *map, int fd, int ac, char **av);

// colors.c
void     init_color(t_rgb *(*floor), t_rgb *(*ceiling));
int		 rgb(int r, int g, int b);
void 	color_it(mlx_image_t* img, t_rgb *draw, char fc);

// // events.c
void	keypress_hook(mlx_key_data_t keycode, void *mlx);
void	close_win(void *mlx);

#endif
