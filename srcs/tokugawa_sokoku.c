/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 15:57:50 by modat            ###   ########.fr       */
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
	if (player_to_wall_dis <= 0.9)
		player_to_wall_dis = 0.9;
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
static void	draw_wall_column(t_tokugawa_sokoku *yakuza, int x,
		mlx_texture_t *tex, double wallx)
{
	t_draw_ints	draw_ints;

	if (!tex)
		return ;
	draw_ints.tex_x = (int)(wallx * tex->width);
	if (draw_ints.tex_x < 0)
		draw_ints.tex_x = 0;
	if (draw_ints.tex_x >= (int)tex->width)
		draw_ints.tex_x = tex->width - 1;
	draw_ints.line_height = yakuza->camera->wall_ends
		- yakuza->camera->wall_starts;
	draw_wall_column_2(yakuza, tex, x, draw_ints);
}

// func - 3
// study if you want to flip
static mlx_texture_t	*choose_texture(t_tokugawa_sokoku *yakuza)
{
	if (yakuza->camera->side == 0)
	{
		if (yakuza->camera->ray_dirx < 0)
			return (yakuza->texture->east);
		else
			return (yakuza->texture->west);
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
		draw_wall_column((*yakuza), x, tex, wallx);
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
