/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:51:56 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:29:22 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	err_close(void *param)
{
	t_tokugawa_sokoku	*yakuza;

	yakuza = (t_tokugawa_sokoku *)param;
	mlx_close_window(yakuza->mlx);
	free_struct(yakuza);
	mlx_terminate(yakuza->mlx);
	exit(1);
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
	if (map->map)
		free_double_array(map->map);
	if (map->cpy_map)
		free_double_array(map->cpy_map);
	if (map->ceiling)
		free(map->ceiling);
	if (map->floor)
		free(map->floor);
	if (map->wall->north)
		free(map->wall->north);
	if (map->wall->south)
		free(map->wall->south);
	if (map->wall->east)
		free(map->wall->east);
	if (map->wall->west)
		free(map->wall->west);
	if (map->wall)
		free(map->wall);
	if (map)
		free(map);
}

// func - 4
void	free_struct(t_tokugawa_sokoku *yakuza)
{
	if (yakuza->minimap && yakuza->minimap->miniimg)
		mlx_delete_image(yakuza->mlx, yakuza->minimap->miniimg);
	if (yakuza->minimap)
		free(yakuza->minimap);
	if (yakuza->map)
		free_map(yakuza->map);
	if (yakuza->camera)
		free(yakuza->camera);
	if (yakuza->kumicho)
		free(yakuza->kumicho);
	if (yakuza->texture && yakuza->texture->north)
		mlx_delete_texture(yakuza->texture->north);
	if (yakuza->texture && yakuza->texture->south)
		mlx_delete_texture(yakuza->texture->south);
	if (yakuza->texture && yakuza->texture->east)
		mlx_delete_texture(yakuza->texture->east);
	if (yakuza->texture && yakuza->texture->west)
		mlx_delete_texture(yakuza->texture->west);
	if (yakuza->texture)
		free(yakuza->texture);
	if (yakuza->mlx)
		mlx_delete_image(yakuza->mlx, yakuza->img);
}
