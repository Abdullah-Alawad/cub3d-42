/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 19:05:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

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
}

void	free_struct(t_tokugawa_sokoku *yakuza)
{
	// tokogawa
	mlx_delete_image(yakuza->mlx, yakuza->img);
	// minimap	
	mlx_delete_image(yakuza->mlx, yakuza->minimap->miniimg);
	free(yakuza->minimap);	
	// mouse 
	free(yakuza->mouse);
	// map
	// free_double_array(yakuza->map->map);
	// free_double_array(yakuza->map->cpy_map);
	free(yakuza->map->floor);
	free(yakuza->map->ceiling);
	
	// free_wall
	free(yakuza->map->wall->north);
	free(yakuza->map->wall->south);
	free(yakuza->map->wall->east);
	free(yakuza->map->wall->west);
	free(yakuza->map->wall);
	free(yakuza->map);

	// free camera
	free(yakuza->camera);
	
	// kumicho
	free(yakuza->kumicho);

	// free texture
	mlx_delete_texture(yakuza->texture->north);
	mlx_delete_texture(yakuza->texture->south);
	mlx_delete_texture(yakuza->texture->east);
	mlx_delete_texture(yakuza->texture->west);
	free(yakuza->texture);
	mlx_delete_texture(yakuza->sky);
	mlx_delete_texture(yakuza->grass);
	
	free(yakuza);
}

// func - 
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
	free_struct(yakuza);
	return (0);
}