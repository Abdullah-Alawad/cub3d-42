/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/13 16:12:47 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
// int	rgb(int r, int g, int b)
// {
// 	return (255 << 24 | (r << 16) | (g << 8) | b);
// 	// return ((r << 16) | (g << 8) | b);
// }

uint32_t rgb(int r, int g, int b)
{
    return ((uint32_t)r << 24)  // alpha
         | ((uint32_t)g << 16)    // red
         | ((uint32_t)b << 8)     // green
         | ((uint32_t)255);         // blue
}

void	color_ceiling(mlx_image_t *img, mlx_texture_t *sky)
{
	for (uint32_t y = 0; y < sky->height && y < HEIGHT; y++)
    {
        for (uint32_t x = 0; x < sky->width && x < WIDTH; x++)
        {
            uint32_t idx = (y * sky->width + x) * 4;
            uint8_t r = sky->pixels[idx + 0];
            uint8_t g = sky->pixels[idx + 1];
            uint8_t b = sky->pixels[idx + 2];
            uint8_t a = sky->pixels[idx + 3];

            mlx_put_pixel(img, x, y, (r << 24) | (g << 16) | (b << 8) | a);
        }
    }
}

void	color_floor(mlx_image_t *img, mlx_texture_t *floor)
{
	int	h = HEIGHT / 2;

	for (uint32_t y = 0; y < floor->height && h < HEIGHT; y++)
    {
        for (uint32_t x = 0; x < floor->width && x < WIDTH; x++)
        {
            uint32_t idx = (y * floor->width + x) * 4;
            uint8_t r = floor->pixels[idx + 0];
            uint8_t g = floor->pixels[idx + 1];
            uint8_t b = floor->pixels[idx + 2];
            uint8_t a = floor->pixels[idx + 3];

            mlx_put_pixel(img, x, h, (r << 24) | (g << 16) | (b << 8) | a);
        }
		h++;
    }
}

// func - 2
void	set_ceiling_floor(t_tokugawa_sokoku **yakuza)
{
	// color_it((*yakuza)->img, (*yakuza)->map->ceiling, 'C'); // ceiling cloor
	color_ceiling((*yakuza)->img, (*yakuza)->sky);			   // ceiling image
	color_floor((*yakuza)->img, (*yakuza)->grass);			   // floor image
	// color_it((*yakuza)->img, (*yakuza)->map->floor, 'F');   // floor color
}

// func - 3
void	color_it(mlx_image_t *img, t_rgb *draw, char fc)
{
	int h;
	int w;
	uint32_t color; 
	
	color = rgb(draw->r, draw->g, draw->b);
	if (fc == 'C')
		h = 0;
	else
		h = HEIGHT/ 2;
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
