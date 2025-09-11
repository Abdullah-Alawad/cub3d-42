/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/04 11:59:23 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// void xx(void)
// {
//      // mlx_texture_t *texture = malloc(sizeof(mlx_texture_t));
//     // texture->height = 300;
//     // texture->width = 600;
//     // texture->bytes_per_pixel = 3;
//     // texture->pixels = malloc(texture->width * texture->height
		* texture->bytes_per_pixel);
//     // if (!texture->pixels)
//     // {
//     //     free(texture);
//     //     return (1);
//     // }
// }

void	load_textures(t_wall **news)
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

int	main(void)
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

	t_rgb *floor = NULL;
	t_rgb *ceiling = NULL;
	void *mlx = NULL;
	mlx_image_t *img = malloc(sizeof(mlx_image_t));
	/// t_wall   *news;

	init_color(&floor, &ceiling);
	init_mlx(&mlx);
	mlx_texture_t *pngImage = malloc(sizeof(mlx_texture_t));
	pngImage->height = HEIGHT;
	pngImage->width = WIDTH;
	pngImage->bytes_per_pixel = 3;
	pngImage->pixels = malloc(pngImage->width * pngImage->height
			* pngImage->bytes_per_pixel);
	// if (!pngImage->pixels)
	// {
	//     free(pngImage);
	//     return (1);
	// }
	pngImage = mlx_load_png("./wall.png");
	if (!pngImage)
	{
		printf("path failed\n");
		exit(1);
	}
	// load_textures(&news);
	img = mlx_texture_to_image(mlx, pngImage);
	if (!img)
	{
		printf("Failed to convert texture to image\n");
		mlx_terminate(mlx);
		return (1);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_close_hook(mlx, close_win, mlx);
	mlx_key_hook(mlx, keypress_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	// mlx_delete_xpm42(&news->north);
	mlx_terminate(mlx);
	return (0);
}