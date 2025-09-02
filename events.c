/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/02 12:10:36 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"


int	close_win(void *mlx, void *win)
{
	// mlx_destroy_image(mlx, img.img);
	mlx_clear_window(mlx, win);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	// free(fractol);
	exit(0);
	return (0);
}

int	keypress_hook(int keycode, void *mlx, void *win)
{
	if (keycode == ESC_KEY)
	{
		// mlx_destroy_image(mlx, img.img);
		mlx_clear_window(mlx, win);
		mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
		// free(fractol);
		exit(0);
	}
	return (0);
}

// int	mouse_hook(int button, int x, int y, t_mlx *fractol)
// {
// 	double	mouse_real;
// 	double	mouse_imag;

// 	mouse_real = (x - WIDTH / 2.0) * (4.0 / (zoom * WIDTH))
// 		+ offset_x;
// 	mouse_imag = (y - HEIGHT / 2.0) * (4.0 / (zoom * HEIGHT))
// 		+ offset_y;
// 	if (button == 4)
// 		zoom *= ZOOM_FACTOR;
// 	else if (button == 5)
// 		zoom /= ZOOM_FACTOR;
// 	else
// 		return (0);
// 	offset_x = mouse_real - (x - WIDTH / 2.0) * (4.0 / (zoom
// 				* WIDTH));
// 	offset_y = mouse_imag - (y - HEIGHT / 2.0) * (4.0 / (zoom
// 				* HEIGHT));
// 	return (0);
// }

// int	arrow_keys(int keycode, t_mlx *fractol)
// {
// 	double	move;

// 	move = MOVE_SPEED / zoom;
// 	if (keycode == KEY_UP)
// 		offset_y -= move;
// 	else if (keycode == KEY_DOWN)
// 		offset_y += move;
// 	else if (keycode == KEY_LEFT)
// 		offset_x -= move;
// 	else if (keycode == KEY_RIGHT)
// 		offset_x += move;
// 	return (0);
// }