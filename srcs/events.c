/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:03 by modat             #+#    #+#             */
/*   Updated: 2025/09/12 14:51:29 by modat            ###   ########.fr       */
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
// int	handle_keys(mlx_key_data_t keycode, t_game *game)
// {
// 	int	new_y;
// 	int	new_x;

// 	// new_y = game->p_y;
// 	// new_x = game->p_x;
// 	// if (keycode.key == MLX_KEY_ESCAPE) // XK_Escape
// 	// 	close_win(game);
// 	if (keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A)
// 		new_x--;
// 	else if (keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D)
// 		new_x++;
// 	else if (keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W)
// 		new_y--;
// 	else if (keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S)
// 		new_y++;
// 	// move_player(game, new_y, new_x);
// 	return (0);
// }

// func - 4 


// func - 5

