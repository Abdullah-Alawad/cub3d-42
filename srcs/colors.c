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

// func - 2
void	set_ceiling_floor(t_tokugawa_sokoku **yakuza)
{
	color_it((*yakuza)->img, (*yakuza)->map->ceiling, 'C');
	color_it((*yakuza)->img, (*yakuza)->map->floor, 'F');
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
