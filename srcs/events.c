/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/04 14:33:45 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void	close_win(void *mlx)
{
	mlx_t	*mlx_tmp;

	mlx_tmp = (mlx_t *)mlx;
	mlx_close_window(mlx_tmp);
	mlx_terminate(mlx_tmp);
	exit(0);
}

void	keypress_hook(mlx_key_data_t keycode, void *mlx)
{
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		close_win(mlx);
		exit(0);
	}
}
