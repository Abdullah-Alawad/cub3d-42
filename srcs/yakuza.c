/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/13 16:22:13 by modat            ###   ########.fr       */
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

void	 setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac)
{
	init_tokugawa_sokoku(&(*yakuza));
	setting_map(&(*yakuza)->map, av, ac);
	init_minimap(&(*yakuza));
	set_ceiling_floor(&(*yakuza));
}
void	draw_background(t_minimap *minimap)
{
	int x;
	int y;

	x = 0;
	while (x < MINI_HEIGHT)
	{
		y = 0;
		while (y < MINI_WIDTH)
		{
			mlx_put_pixel(minimap->miniimg, y, x, 0xBBBBBBBB);
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_tokugawa_sokoku *yakuza;
	
	setup_config(&yakuza, av, ac);
	draw_background(yakuza->minimap);
	minimap(yakuza->minimap, yakuza->map);
	// xy ???
	// mouse_hook(yakuza->mouse, yakuza, yakuza->mlx);

	
	// start_the_game
	// enter_tokugawa_sokoku(yakuza);
	
	// print_map(yakuza->map);
	/* Do stuff */
// rendering 
	mlx_key_hook(yakuza->mlx, keypress_hook, yakuza->mlx);
	mlx_close_hook(yakuza->mlx, close_win, yakuza->mlx);
	mlx_loop(yakuza->mlx);
	mlx_terminate(yakuza->mlx);
	return (0);
}