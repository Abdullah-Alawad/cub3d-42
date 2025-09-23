/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:53:20 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 00:00:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static void	draw(t_minimap *minimap, uint32_t color, t_ints start, t_ints p)
{
	int	y;
	int	x;
	int	px;
	int	py;

	y = 0;
	while (y < p.h)
	{
		x = 0;
		while (x < p.w)
		{
			px = start.w + x;
			py = start.h + y;
			if (px >= 0 && px < MINI_WIDTH && py >= 0 && py < MINI_HEIGHT)
			{
				mlx_put_pixel(minimap->miniimg, px, py, color);
			}
			x++;
		}
		y++;
	}
}

// func - 2
void	minimap(t_minimap *minimap, t_map *map)
{
	t_ints		cell;
	t_ints		start;
	int			h;
	int			w;
	uint32_t	color;

	cell.w = MINI_WIDTH / map->width;
	cell.h = MINI_HEIGHT / map->height;
	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			color = 0x00000033;
			if (map->map[h][w] == '1')
				color = 0xBBDDFBBB;
			else if (map->map[h][w] == '0')
				color = 0xFFFFFFFF;
			else if (map->map[h][w] == 'N')
				color = 0xFF0000FF;
			start.w = w * cell.w;
			start.h = h * cell.h;
			draw(minimap, color, start, cell);
			w++;
		}
		h++;
	}
}

// func - 3
void	draw_background(t_minimap *minimap)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINI_HEIGHT)
	{
		y = 0;
		while (y < MINI_WIDTH)
		{
			mlx_put_pixel(minimap->miniimg, y, x, 0xBBBBBBBB);
			y++;
		}
		x++;
	}
}
