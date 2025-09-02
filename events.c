/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/02 12:16:19 by modat            ###   ########.fr       */
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
		//mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
		// free(fractol);
		exit(0);
	}
	return (0);
}
