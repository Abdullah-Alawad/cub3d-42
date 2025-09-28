/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:54:28 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	close_win(void *param)
{
	t_tokugawa_sokoku	*yakuza;

	yakuza = (t_tokugawa_sokoku *)param;
	mlx_close_window(yakuza->mlx);
	free_struct(yakuza);
	mlx_terminate(yakuza->mlx);
	exit(0);
}

// func - 2
void	keypress_hook(mlx_key_data_t keycode, void *param)
{
	t_tokugawa_sokoku	*yakuza;

	yakuza = (t_tokugawa_sokoku *)param;
	if (keycode.key == MLX_KEY_ESCAPE)
		mlx_close_window(yakuza->mlx);
}

// func - 3
void	rotate_right(t_tokugawa_sokoku *yakuza, double rotation_speed, char dir)
{
	double	old_dir_w;
	double	old_plane_w;

	old_dir_w = yakuza->kumicho->direction.w;
	old_plane_w = yakuza->kumicho->plane.w;
	if (dir == 'N' || dir == 'S')
		rotation_speed = -rotation_speed;
	yakuza->kumicho->direction.w = (yakuza->kumicho->direction.w
			* cos(-rotation_speed)) - (yakuza->kumicho->direction.h
			* sin(-rotation_speed));
	yakuza->kumicho->direction.h = (old_dir_w * sin(-rotation_speed))
		+ (yakuza->kumicho->direction.h * cos(-rotation_speed));
	yakuza->kumicho->plane.w = (yakuza->kumicho->plane.w * cos(-rotation_speed))
		- (yakuza->kumicho->plane.h * sin(-rotation_speed));
	yakuza->kumicho->plane.h = (old_plane_w * sin(-rotation_speed))
		+ (yakuza->kumicho->plane.h * cos(-rotation_speed));
}

// // func - 4
void	rotate_left(t_tokugawa_sokoku *yakuza, double rotation_speed, char dir)
{
	double	old_dir_w;
	double	old_plane_w;

	old_dir_w = yakuza->kumicho->direction.w;
	old_plane_w = yakuza->kumicho->plane.w;
	if (dir == 'N' || dir == 'S')
		rotation_speed = -rotation_speed;
	yakuza->kumicho->direction.w = (yakuza->kumicho->direction.w
			* cos(rotation_speed)) - (yakuza->kumicho->direction.h
			* sin(rotation_speed));
	yakuza->kumicho->direction.h = (old_dir_w * sin(rotation_speed))
		+ (yakuza->kumicho->direction.h * cos(rotation_speed));
	yakuza->kumicho->plane.w = (yakuza->kumicho->plane.w * cos(rotation_speed))
		- (yakuza->kumicho->plane.h * sin(rotation_speed));
	yakuza->kumicho->plane.h = (old_plane_w * sin(rotation_speed))
		+ (yakuza->kumicho->plane.h * cos(rotation_speed));
}
