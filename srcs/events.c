/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 18:11:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	close_win(void *mlx)
{
	mlx_t	*mlx_tmp;

	mlx_tmp = (mlx_t *)mlx;
	mlx_close_window(mlx_tmp);
	mlx_terminate(mlx_tmp);
	exit(0);
}

// func - 2
void	keypress_hook(mlx_key_data_t keycode, void *mlx)
{
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		close_win(mlx);
		exit(0);
	}
}

// func - 3
void	handle_keys(mlx_key_data_t keycode, t_tokugawa_sokoku *yakuza)
{
	if (keycode.key == MLX_KEY_A)
		left(yakuza);
	else if (keycode.key == MLX_KEY_D)
		right(yakuza);
	else if (keycode.key == MLX_KEY_W)
		forward(yakuza);
	else if (keycode.key == MLX_KEY_S)
		backward(yakuza);
	else if (keycode.key == MLX_KEY_LEFT)
		rotate_left(yakuza, ROT_SPEED);
	else if (keycode.key == MLX_KEY_RIGHT)
		rotate_right(yakuza, ROT_SPEED);
}

// func - 4
// void	mouse_hook(t_mouse *xy, t_tokugawa_sokoku *yakuza, mlx_t *mlx)
// {
// 	int32_t x;
// 	int32_t y;
// 	double 	rot;

// 	mlx_get_mouse_pos(mlx, &x, &y);
// 	rot = ROT_SPEED * (abs(xy->x - x));
// 	// mlx_get_mouse_pos(mlx, &xy->x, &xy->y);
// 	if (x > xy->x)
// 		rotate_right(yakuza, rot);
// 	else if (x < xy->x)
// 		rotate_left(yakuza, rot);
// 	mlx_cursor_hook(window, mouse_move_callback, &player);
// mlx_set_cursor_mode(window, MLX_MOUSE_DISABLED);
// Hide cursor and lock to window

// 	printf("Mouse position: %d, %d\n", x, y);
// }
