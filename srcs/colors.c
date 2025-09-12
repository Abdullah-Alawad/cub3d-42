/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/12 12:48:34 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

// func - 2
void	draw_img(mlx_t *mlx, t_rgb *draw, char fc)
{
	mlx_image_t	*img = NULL;

	if (fc == 'C')
	{
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			return ;
	}
	else if (fc == 'F')
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
	draw_img(mlx, floor, 'F');
	draw_img(mlx, ceiling, 'C');
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
		if (fc == 'C')
			height = HEIGHT / 2;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, rgb(draw->r, draw->g, draw->b));
			y++;
		}
		x++;
	}
}