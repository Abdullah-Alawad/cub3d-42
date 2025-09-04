/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/04 14:56:44 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void    load_textures(t_wall **news)
{
    (*news) = malloc(sizeof(t_wall));
    if (!*news)
    {
        // free
        exit(0);
    }
    (*news)->north = mlx_load_xpm42("./wall.xpm42");
    if (!(*news)->north)
        printf("path error\n");
    (*news)->south = mlx_load_xpm42("texture/wall.xpm42");
    (*news)->east = mlx_load_xpm42("texture/wall_window.xpm42");
    (*news)->west = mlx_load_xpm42("texture/wall.xpm42");
}

int     main(void)
{
    // char map[7][29] =
    // {
    //     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    //     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    // };
    

    t_rgb   *floor = NULL;
    t_rgb   *ceiling = NULL;
    mlx_t    *mlx;
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    
    init_color(&floor, &ceiling);
    init_mlx(&mlx);
    set_ceiling_floor(mlx, floor, ceiling, img);
	/* Do stuff */
    
	
    // mlx_image_to_window(mlx, img, i, j);
    mlx_key_hook(mlx, keypress_hook, mlx);
    mlx_close_hook(mlx, close_win, mlx);
    // mlx_loop_hook(mlx, close);
	mlx_loop(mlx);
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return (0);
}