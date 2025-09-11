/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/11 18:45:01 by modat            ###   ########.fr       */
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
// void    load_textures(t_wall **news)
// {
//     (*news) = malloc(sizeof(t_wall));
//     if (!*news)
//     {
//         // free
//         exit(0);
//     }
//     (*news)->north = mlx_load_xpm42("./wall.xpm42");
//     if (!(*news)->north)
//         printf("path error\n");
//     (*news)->south = mlx_load_xpm42("texture/wall.xpm42");
//     (*news)->east = mlx_load_xpm42("texture/wall_window.xpm42");
//     (*news)->west = mlx_load_xpm42("texture/wall.xpm42");
// }

int	main(int ac, char **av)
{
	t_map *map;

	allocate_map(&map);
	if (parsing_reading(ac, av, &map) == 1)
	{
		// error & free
		return (1);
	}
	if (map->player_count != 1)
    {
        printf("players numbers is incorrect\n");
        exit(1);
    }
	print_map(map);
	// mlx_t    *mlx;
	// init_mlx(&mlx);
	// init_map(map, fd, ac, av);
	// /* Do stuff */

	// mlx_key_hook(mlx, keypress_hook, mlx);
	// mlx_close_hook(mlx, close_win, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (0);
}