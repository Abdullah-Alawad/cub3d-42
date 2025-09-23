/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 17:31:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
uint32_t	rgb(int r, int g, int b)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | ((uint32_t)255));
}

// func - 2
void	color_ceiling(mlx_image_t *img, mlx_texture_t *sky)
{
	uint32_t	idx;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	for (uint32_t y = 0; y < sky->height && y < HEIGHT; y++)
	{
		for (uint32_t x = 0; x < sky->width && x < WIDTH; x++)
		{
			idx = (y * sky->width + x) * 4;
			r = sky->pixels[idx + 0];
			g = sky->pixels[idx + 1];
			b = sky->pixels[idx + 2];
			a = sky->pixels[idx + 3];
			mlx_put_pixel(img, x, y, (r << 24) | (g << 16) | (b << 8) | a);
		}
	}
}

// func - 3
void	color_floor(mlx_image_t *img, mlx_texture_t *floor)
{
	int			h;
	uint32_t	idx;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	h = HEIGHT / 2;
	for (uint32_t y = 0; y < floor->height && h < HEIGHT; y++)
	{
		for (uint32_t x = 0; x < floor->width && x < WIDTH; x++)
		{
			idx = (y * floor->width + x) * 4;
			r = floor->pixels[idx + 0];
			g = floor->pixels[idx + 1];
			b = floor->pixels[idx + 2];
			a = floor->pixels[idx + 3];
			mlx_put_pixel(img, x, h, (r << 24) | (g << 16) | (b << 8) | a);
		}
		h++;
	}
}

// func - 4
void	set_ceiling_floor(t_tokugawa_sokoku **yakuza)
{
	color_ceiling((*yakuza)->img, (*yakuza)->sky);
	color_floor((*yakuza)->img, (*yakuza)->grass);
}

// func - 5
void	color_it(mlx_image_t *img, t_rgb *draw, char fc)
{
	int			h;
	int			w;
	uint32_t	color;

	color = rgb(draw->r, draw->g, draw->b);
	if (fc == 'C')
		h = 0;
	else
		h = HEIGHT / 2;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			if (fc == 'C')
				mlx_put_pixel(img, w, h, color);
			else if (fc == 'F')
				mlx_put_pixel(img, w, h, color);
			w++;
		}
		h++;
	}
}
