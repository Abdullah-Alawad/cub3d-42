/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/08 20:52:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

/*
TODO :
- fix it to start from parsing and reading.
- init the inputs and allocate memory for each struct I will make.
- test it and ensure it is assigning correctly.
- it is fine to do a little parsing.

*/
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

int     main(int ac, char **av)
{
     if (ac < 2)
        return (1);
    int fd;
    fd = open("map.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    // parsing_reading(ac, av);
    t_rgb   *floor = NULL;
    t_rgb   *ceiling = NULL;
    mlx_t    *mlx;
    t_map   *map;
    init_mlx(&mlx);
	// mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    init_map(map, fd, ac, av);
    init_color(&floor, &ceiling);
    set_ceiling_floor(mlx, floor, ceiling);
	/* Do stuff */
    
	
    // mlx_image_to_window(mlx, img, i, j);
    mlx_key_hook(mlx, keypress_hook, mlx);
    mlx_close_hook(mlx, close_win, mlx);
    // mlx_loop_hook(mlx, close);
	mlx_loop(mlx);
    // mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return (0);
}