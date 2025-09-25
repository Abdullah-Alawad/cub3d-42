/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:53:20 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 10:46:50 by modat            ###   ########.fr       */
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

static void	minimap_2(t_minimap *minimap, t_map *map, t_ints cell, t_ints start)
{
	int			h;
	int			w;
	int			width;
	uint32_t	color;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		width = ft_strlen(map->map[h]);
		while (w < width)
		{
			color = 0x00000033;
			minimap_color(map, h, w, &color);
			start.w = w * cell.w;
			start.h = h * cell.h;
			draw(minimap, color, start, cell);
			w++;
		}
		h++;
	}
}

// func - 2
void	minimap(t_minimap *minimap, t_map *map)
{
	t_ints	cell;
	t_ints	start;

	start.w = 0.0;
	cell.w = MINI_WIDTH / map->width;
	cell.h = MINI_HEIGHT / map->height;
	minimap_2(minimap, map, cell, start);
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

// func - 5
void	frees(char *str)
{
	if (str)
		free(str);
	str = NULL;
}
