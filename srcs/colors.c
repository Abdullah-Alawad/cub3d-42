/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:57:11 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
uint32_t	rgb(int r, int g, int b)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | ((uint32_t)255));
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

// func - 4
void	draw_wall_column_2(t_tokugawa_sokoku *yakuza, mlx_texture_t *tex, int x,
		t_draw_ints draw_ints)
{
	int			y;
	uint32_t	idx;
	uint8_t		rgba[4];

	y = yakuza->camera->wall_starts;
	while (y < yakuza->camera->wall_ends)
	{
		draw_ints.d = y * 256 - HEIGHT * 128 + draw_ints.line_height * 128;
		draw_ints.tex_y = ((draw_ints.d * tex->height) / draw_ints.line_height)
			/ 256;
		if (draw_ints.tex_y < 0)
			draw_ints.tex_y = 0;
		if (draw_ints.tex_y >= (int)tex->height)
			draw_ints.tex_y = tex->height - 1;
		idx = (draw_ints.tex_y * tex->width + draw_ints.tex_x) * 4;
		rgba[0] = tex->pixels[idx + 0];
		rgba[1] = tex->pixels[idx + 1];
		rgba[2] = tex->pixels[idx + 2];
		rgba[3] = tex->pixels[idx + 3];
		mlx_put_pixel(yakuza->img, x, y,
			(rgba[0] << 24) | (rgba[1] << 16) | (rgba[2] << 8) | rgba[3]);
		y++;
	}
}

// func - 5
int	color_split(char **comb, int k)
{
	int	x;

	if (comb[k] == NULL)
		x = -1;
	else
		x = ft_atoi(comb[k]);
	return (x);
}
