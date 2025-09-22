/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/22 15:25:10 by modat            ###   ########.fr       */
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

void 	init_texture(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->texture = malloc(sizeof(t_news_tex));
    if (!(*yakuza)->texture)
    {
        perror("xpm");
        return ;
    }
	// char s[20] = ft_strtrim();
	(*yakuza)->texture->north = mlx_load_png((*yakuza)->map->wall->north);
	(*yakuza)->texture->south = mlx_load_png((*yakuza)->map->wall->south);
	(*yakuza)->texture->east = mlx_load_png((*yakuza)->map->wall->east);
	(*yakuza)->texture->west = mlx_load_png((*yakuza)->map->wall->west);


	if (!(*yakuza)->texture->north || !(*yakuza)->texture->east || !(*yakuza)->texture->south || !(*yakuza)->texture->west)
	{
    	fprintf(stderr, "Texture not loaded!\n");
    	return ;
	}
}

void	 setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac)
{
	init_tokugawa_sokoku(&(*yakuza));
	setting_map(&(*yakuza)->map, av, ac);
	// set_ceiling_floor(&(*yakuza));
	print_cpy((*yakuza)->map->cpy_map, (*yakuza)->map->height);
	print_cpy((*yakuza)->map->map, (*yakuza)->map->height);
	/*   sky and grass*/
	(*yakuza)->sky = mlx_load_png("texture/sky.png");
	if (!(*yakuza)->sky)
        fprintf(stderr, "Failed to load PNG!\n");
	
	(*yakuza)->grass = mlx_load_png("texture/grass.png");
	if (!(*yakuza)->grass)
        fprintf(stderr, "Failed to load PNG!\n");

	init_texture(&(*yakuza));
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