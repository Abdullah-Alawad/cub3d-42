/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:51:56 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 23:47:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	malloc_err(void)
{
	perror("malloc falied\n");
	exit(EXIT_FAILURE);
}

// func - 2
void	free_double_array(char **doub)
{
	int	k;

	if (!doub)
		return ;
	k = 0;
	while (doub[k])
	{
		free(doub[k]);
		k++;
	}
	free(doub);
}

// func - 3
void	free_map(t_map *map)
{
	free_double_array(map->map);
	free_double_array(map->cpy_map);
	free(map->floor);
	free(map->ceiling);
	free(map->wall->north);
	free(map->wall->south);
	free(map->wall->east);
	free(map->wall->west);
	free(map->wall);
	free(map);
}

// func - 4
void	free_struct(t_tokugawa_sokoku *yakuza)
{
	mlx_delete_image(yakuza->mlx, yakuza->img);
	mlx_delete_image(yakuza->mlx, yakuza->minimap->miniimg);
	free(yakuza->minimap);
	free_map(yakuza->map);
	free(yakuza->camera);
	free(yakuza->kumicho);
	mlx_delete_texture(yakuza->texture->north);
	mlx_delete_texture(yakuza->texture->south);
	mlx_delete_texture(yakuza->texture->east);
	mlx_delete_texture(yakuza->texture->west);
	free(yakuza->texture);
	mlx_delete_texture(yakuza->sky);
	mlx_delete_texture(yakuza->grass);
	free(yakuza);
}
