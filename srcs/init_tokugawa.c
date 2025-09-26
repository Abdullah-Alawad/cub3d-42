/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokugawa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:07:17 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 00:03:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func -1
static int	init_mlx(mlx_t **mlx)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	(*mlx) = mlx_init(WIDTH, HEIGHT, "YAKUZA", true);
	if (!(*mlx))
	{
		strerror(mlx_errno);
		return (0);
	}
	return (1);
}

// func - 2
int	init_minimap(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->minimap = malloc(sizeof(t_minimap));
	if (!(*yakuza)->minimap)
	{
		ft_putstr_fd("Error:\nminimap malloc failed\n", 2);
		free_struct(*yakuza);
		exit(1);
	}
	(*yakuza)->minimap->h = 0;
	(*yakuza)->minimap->w = 0;
	(*yakuza)->minimap->miniimg = mlx_new_image((*yakuza)->mlx, MINI_WIDTH,
			MINI_HEIGHT);
	if (!(*yakuza)->minimap->miniimg || (mlx_image_to_window((*yakuza)->mlx,
				(*yakuza)->minimap->miniimg, 20, 20) < 0))
	{
		ft_putstr_fd("Error:\nminimap img malloc failed\n", 2);
		free_struct(*yakuza);
		exit(1);
	}
	return (1);
}

// func - 3
void	init_camera(t_tokugawa_sokoku **yakuza, int x)
{
	(*yakuza)->camera->camerax = 2 * x / (double)WIDTH - 1;
	(*yakuza)->camera->ray_dirx = (*yakuza)->kumicho->direction.w
		+ (*yakuza)->kumicho->plane.w * (*yakuza)->camera->camerax;
	(*yakuza)->camera->ray_diry = (*yakuza)->kumicho->direction.h
		+ (*yakuza)->kumicho->plane.h * (*yakuza)->camera->camerax;
	(*yakuza)->camera->mapx = (int)(*yakuza)->kumicho->offset.w;
	(*yakuza)->camera->mapy = (int)(*yakuza)->kumicho->offset.h;
	(*yakuza)->camera->delta_disx = fabs(1 / (*yakuza)->camera->ray_dirx);
	(*yakuza)->camera->delta_disy = fabs(1 / (*yakuza)->camera->ray_diry);
	side_dis(&(*yakuza));
	(*yakuza)->camera->player_to_wall_dis = 0.0;
}

// func - 4
int	init_kumicho(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->kumicho = malloc(sizeof(t_kumicho));
	if (!(*yakuza)->kumicho)
	{
		ft_putstr_fd("Error:\nkumicho init failed\n", 2);
		free_struct((*yakuza));
		exit(1);
	}
	init_kumicho_2(&(*yakuza));
	return (1);
}

// func - 5
int	init_tokugawa_sokoku(t_tokugawa_sokoku **yakuza)
{
	(*yakuza) = malloc(sizeof(t_tokugawa_sokoku));
	if (!(*yakuza))
	{
		ft_putstr_fd("Error:\nyakuza malloc: failed\n", 2);
		return (0);
	}
	if (init_mlx(&(*yakuza)->mlx) == 0)
	{
		ft_putstr_fd("Error:\nmlx_init(): failed\n", 2);
		free (*yakuza);
		return (0);
	}
	(*yakuza)->img = mlx_new_image((*yakuza)->mlx, WIDTH, HEIGHT);
	if (!(*yakuza)->img || (mlx_image_to_window((*yakuza)->mlx, (*yakuza)->img,
				0, 0) < 0))
	{
		mlx_terminate((*yakuza)->mlx);
		free(*yakuza);
		ft_putstr_fd("Error:\nmlx_new_img(): failed\n", 2);
		return (0);
	}
	set_default_values(&(*yakuza));
	return (1);
}
