/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/21 16:02:29 by modat            ###   ########.fr       */
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

void	 setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac)
{
	init_tokugawa_sokoku(&(*yakuza));
	setting_map(&(*yakuza)->map, av, ac);
	// set_ceiling_floor(&(*yakuza));
	init_kumicho(&(*yakuza));
	(*yakuza)->camera = malloc(sizeof(t_camera));
	if (!(*yakuza)->camera)
		malloc_err();
	init_minimap(&(*yakuza));
	// init_camera(&(*yakuza), 0);
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



void 	map_drawing(t_tokugawa_sokoku *yakuza, uint32_t color, int pw, int ph)
{
    int w;
    int h;
    int wCopy = yakuza->map->width;
    int hCopy = yakuza->map->height;
    h = 0;
    while (h < ph)
    {
        wCopy = yakuza->map->width;
        w = 0;
        while (w < pw)
        {
			mlx_put_pixel(yakuza->img, wCopy, hCopy, color);
            w++;
            wCopy++;
        }
        h++;
        hCopy++;
    }
}

int	main(int ac, char **av)
{
	t_tokugawa_sokoku *yakuza;
	
	setup_config(&yakuza, av, ac);


	
	// mouse_hook(yakuza->mouse, yakuza, yakuza->mlx);
	mlx_close_hook(yakuza->mlx, close_win, yakuza->mlx);
	mlx_key_hook(yakuza->mlx, keypress_hook, yakuza->mlx);
	mlx_loop_hook(yakuza->mlx, enter_tokugawa_sokoku, yakuza);
	mlx_loop(yakuza->mlx);
	mlx_terminate(yakuza->mlx);
	return (0);
}