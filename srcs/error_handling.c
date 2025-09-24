/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:51:56 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 11:10:37 by modat            ###   ########.fr       */
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
	if (yakuza->minimap->miniimg)
		mlx_delete_image(yakuza->mlx, yakuza->minimap->miniimg);
	if (yakuza->minimap)
		free(yakuza->minimap);
	if (yakuza->map)
		free_map(yakuza->map);
	if (yakuza->camera)
		free(yakuza->camera);
	if (yakuza->kumicho)
		free(yakuza->kumicho);
	if (yakuza->texture->north)
		mlx_delete_texture(yakuza->texture->north);
	if (yakuza->texture->south)
		mlx_delete_texture(yakuza->texture->south);
	if (yakuza->texture->east)
		mlx_delete_texture(yakuza->texture->east);
	if (yakuza->texture->west)
		mlx_delete_texture(yakuza->texture->west);
	if (yakuza->texture)
		free(yakuza->texture);
	if (yakuza->mlx)
		mlx_delete_image(yakuza->mlx, yakuza->img);
}

// func - 5
void	invalid_path(char *str)
{
	free(str);
	write(2, "Error: invalid path\n", 20);
	exit(1);
}
