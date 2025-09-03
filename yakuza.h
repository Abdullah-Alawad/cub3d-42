/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:53:36 by modat             #+#    #+#             */
/*   Updated: 2025/09/03 21:54:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YAKUZA_H
#define YAKUZA_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <MLX42/MLX42.h>

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

int	keypress_hook(int keycode, void *mlx, void *win);
int	close_win(void *mlx, void *win);

#endif