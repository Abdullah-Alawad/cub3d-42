/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/20 18:45:03 by marvin           ###   ########.fr       */
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
	init_minimap(&(*yakuza));
	set_ceiling_floor(&(*yakuza));
	init_kumicho(&(*yakuza));
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

void 	map(t_tokugawa_sokoku *yakuza)
{
	int h = 0;
	int w;
	int ph = HEIGHT / yakuza->map->height;
	int pw = WIDTH / yakuza->map->width;
	yakuza->map->height = 0;
	while (yakuza->map->map[h])
	{
		yakuza->map->width = 0;
		w = 0;
		while (yakuza->map->map[h][w])
		{
			if (yakuza->map->map[h][w] == '1')
                map_drawing(yakuza, 0xBBDDFBBB, pw, ph);
			if (yakuza->map->map[h][w] == 'N')
                map_drawing(yakuza, 0xBBDAABBB, pw, ph);
			w++;
			yakuza->map->width += pw;
		}
		yakuza->map->height += ph;
		h++;
	}
}



int	main(int ac, char **av)
{
	t_tokugawa_sokoku *yakuza;
	
	setup_config(&yakuza, av, ac);
	// draw_background(yakuza->minimap);
	// minimap(yakuza->minimap, yakuza->map);
	// map(yakuza);

	
	// mouse_hook(yakuza->mouse, yakuza, yakuza->mlx);
	
	mlx_loop_hook(yakuza->mlx, enter_tokugawa_sokoku, yakuza);
	mlx_key_hook(yakuza->mlx, keypress_hook, yakuza->mlx);
	mlx_close_hook(yakuza->mlx, close_win, yakuza->mlx);
	// mlx_loop(yakuza->mlx);
	mlx_terminate(yakuza->mlx);
	return (0);
}