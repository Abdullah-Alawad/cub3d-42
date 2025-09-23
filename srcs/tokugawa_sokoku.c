/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 23:55:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static void	find_wall_height(t_tokugawa_sokoku **yakuza)
{
	double	player_to_wall_dis;
	int		wall_len;

	if ((*yakuza)->camera->side == 0)
		player_to_wall_dis = ((*yakuza)->camera->mapx
				- (*yakuza)->kumicho->offset.w + (1 - (*yakuza)->camera->stepx)
				/ 2) / (*yakuza)->camera->ray_dirx;
	else
		player_to_wall_dis = ((*yakuza)->camera->mapy
				- (*yakuza)->kumicho->offset.h + (1 - (*yakuza)->camera->stepy)
				/ 2) / (*yakuza)->camera->ray_diry;
	(*yakuza)->camera->player_to_wall_dis = player_to_wall_dis;
	wall_len = ((int)HEIGHT / player_to_wall_dis);
	(*yakuza)->camera->wall_starts = -wall_len / 2 + HEIGHT / 2;
	if ((*yakuza)->camera->wall_starts < 0)
		(*yakuza)->camera->wall_starts = 0;
	(*yakuza)->camera->wall_ends = wall_len / 2 + HEIGHT / 2;
	if ((*yakuza)->camera->wall_ends > HEIGHT)
		(*yakuza)->camera->wall_ends = HEIGHT - 1;
}

// func - 2
static void	draw_wall_column(mlx_image_t *img, int x, int wall_start,
		int wall_end, mlx_texture_t *tex, double wallx)
{
	int			texX;
	int			lineHeight;
	int			d;
	int			texY;
	uint32_t	idx;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	if (!tex)
		return ;
	texX = (int)(wallx * tex->width);
	if (texX < 0)
		texX = 0;
	if (texX >= (int)tex->width)
		texX = tex->width - 1;
	lineHeight = wall_end - wall_start;
	for (int y = wall_start; y < wall_end; y++)
	{
		d = y * 256 - HEIGHT * 128 + lineHeight * 128;
		texY = ((d * tex->height) / lineHeight) / 256;
		if (texY < 0)
			texY = 0;
		if (texY >= (int)tex->height)
			texY = tex->height - 1;
		idx = (texY * tex->width + texX) * 4;
		r = tex->pixels[idx + 0];
		g = tex->pixels[idx + 1];
		b = tex->pixels[idx + 2];
		a = tex->pixels[idx + 3];
		mlx_put_pixel(img, x, y, (r << 24) | (g << 16) | (b << 8) | a);
	}
}

// func - 3
static mlx_texture_t	*choose_texture(t_tokugawa_sokoku *yakuza)
{
	if (yakuza->camera->side == 0)
	{
		if (yakuza->camera->ray_dirx < 0)
			return (yakuza->texture->west);
		else
			return (yakuza->texture->east);
	}
	else
	{
		if (yakuza->camera->ray_diry > 0)
			return (yakuza->texture->north);
		else
			return (yakuza->texture->south);
	}
}

// func - 4
static void	raycasting(t_tokugawa_sokoku **yakuza)
{
	int				x;
	double			wallx;
	mlx_texture_t	*tex;

	x = 0;
	while (x < WIDTH)
	{
		init_camera(&(*yakuza), x);
		dis_to_wall(&(*yakuza));
		find_wall_height(&(*yakuza));
		if ((*yakuza)->camera->side == 0)
			wallx = (*yakuza)->kumicho->offset.h
				+ (*yakuza)->camera->player_to_wall_dis
				* (*yakuza)->camera->ray_diry;
		else
			wallx = (*yakuza)->kumicho->offset.w
				+ (*yakuza)->camera->player_to_wall_dis
				* (*yakuza)->camera->ray_dirx;
		wallx -= floor(wallx);
		tex = choose_texture(*yakuza);
		draw_wall_column((*yakuza)->img, x, (*yakuza)->camera->wall_starts,
			(*yakuza)->camera->wall_ends, tex, wallx);
		x++;
	}
}

// func - 5
void	enter_tokugawa_sokoku(void *land)
{
	t_tokugawa_sokoku	*yakuza;

	yakuza = (t_tokugawa_sokoku *)land;
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_W))
		forward(yakuza);
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_S))
		backward(yakuza);
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_A))
		left(yakuza);
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_D))
		right(yakuza);
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_LEFT))
		rotate_left(yakuza, ROT_SPEED);
	if (mlx_is_key_down(yakuza->mlx, MLX_KEY_RIGHT))
		rotate_right(yakuza, ROT_SPEED);
	set_ceiling_floor(&(yakuza));
	raycasting(&yakuza);
	minimap(yakuza->minimap, yakuza->map);
}
