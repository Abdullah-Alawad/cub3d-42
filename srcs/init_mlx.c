/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:07:17 by modat             #+#    #+#             */
/*   Updated: 2025/09/09 07:42:27 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func -1
void	init_mlx(mlx_t **mlx)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	(*mlx) = mlx_init(WIDTH, HEIGHT, "YAKUZA", true);
	if (!(*mlx))
	{
		strerror(mlx_errno);
		return ;
	}
}

// func - 2
void	draw_img(mlx_t *mlx, t_rgb *draw, char fc)
{
	mlx_image_t	*img;

	if (fc == 'c')
	{
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			return ;
	}
	else if (fc == 'f')
	{
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img || (mlx_image_to_window(mlx, img, 0, HEIGHT / 2) < 0))
			return ;
	}
	color_it(img, draw, fc);
}

// func - 3
void	set_ceiling_floor(mlx_t *mlx, t_rgb *floor, t_rgb *ceiling)
{
	// (void)ceiling;
	draw_img(mlx, floor, 'f');
	draw_img(mlx, ceiling, 'c');
}

// func - 4
void	color_it(mlx_image_t *img, t_rgb *draw, char fc)
{
	int	x;
	int	y;
	int	height;

	x = 0;
	y = 0;
	height = 0;
	while (x < WIDTH)
	{
		y = 0;
		if (fc == 'c')
			height = HEIGHT / 2;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, rgb(draw->r, draw->g, draw->b));
			y++;
		}
		x++;
	}
}
