/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokugawa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:07:17 by modat             #+#    #+#             */
/*   Updated: 2025/09/12 17:41:09 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func -1
void	init_mlx(mlx_t **mlx)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	(*mlx) = mlx_init(WIDTH, HEIGHT, "YAKUZA", true);
	if (!(*mlx))
	{
		strerror(mlx_errno);
		return ;
	}
}

// func - 2
// static void 	init_kumicho(t_kumicho **kumicho)
// {
// 	(*kumicho) = malloc(sizeof(t_kumicho));
// 	if (!(*kumicho))
// 		malloc_err();
// 	(*kumicho)->h_offset = 0;
// 	(*kumicho)->w_offset = 0;
		
// }
void 	init_minimap(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->minimap = malloc(sizeof(t_minimap));
	if (!(*yakuza)->minimap)
		malloc_err();
	(*yakuza)->minimap->h = 0;
	(*yakuza)->minimap->w = 0;
	(*yakuza)->minimap->miniimg = mlx_new_image((*yakuza)->mlx, MINI_WIDTH , MINI_HEIGHT);
    if (!(*yakuza)->minimap->miniimg || (mlx_image_to_window((*yakuza)->mlx, (*yakuza)->minimap->miniimg, 20, 20) < 0))
		return ;
}

// func - 3
void 	init_tokugawa_sokoku(t_tokugawa_sokoku **yakuza)
{
	(*yakuza) = malloc(sizeof(t_tokugawa_sokoku));
	if (!(*yakuza))
		malloc_err();
	// init_kumicho(&(*yakuza)->kumicho);
	init_mlx(&(*yakuza)->mlx);
	init_minimap(&(*yakuza));
}

// func - 4

// func - 5

