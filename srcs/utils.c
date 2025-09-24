/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:25:39 by marvin            #+#    #+#             */
/*   Updated: 2025/09/24 15:16:54 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	side_dis(t_tokugawa_sokoku **yakuza)
{
	if ((*yakuza)->camera->ray_dirx < 0)
	{
		(*yakuza)->camera->stepx = -1;
		(*yakuza)->camera->side_disx = ((*yakuza)->kumicho->offset.w
				- (*yakuza)->camera->mapx) * (*yakuza)->camera->delta_disx;
	}
	else
	{
		(*yakuza)->camera->stepx = 1;
		(*yakuza)->camera->side_disx = ((*yakuza)->camera->mapx + 1.0
				- (*yakuza)->kumicho->offset.w) * (*yakuza)->camera->delta_disx;
	}
	if ((*yakuza)->camera->ray_diry < 0)
	{
		(*yakuza)->camera->stepy = -1;
		(*yakuza)->camera->side_disy = ((*yakuza)->kumicho->offset.h
				- (*yakuza)->camera->mapy) * (*yakuza)->camera->delta_disy;
	}
	else
	{
		(*yakuza)->camera->stepy = 1;
		(*yakuza)->camera->side_disy = ((*yakuza)->camera->mapy + 1.0
				- (*yakuza)->kumicho->offset.h) * (*yakuza)->camera->delta_disy;
	}
}

// func - 2
void	dis_to_wall(t_tokugawa_sokoku **yakuza)
{
	int	hit;
	int	maph;
	int	mapw;

	hit = 0;
	(*yakuza)->camera->side *= 1;
	while (!hit)
	{
		if ((*yakuza)->camera->side_disx < (*yakuza)->camera->side_disy)
		{
			(*yakuza)->camera->side_disx += (*yakuza)->camera->delta_disx;
			(*yakuza)->camera->mapx += (*yakuza)->camera->stepx;
			(*yakuza)->camera->side = 0;
		}
		else
		{
			(*yakuza)->camera->side_disy += (*yakuza)->camera->delta_disy;
			(*yakuza)->camera->mapy += (*yakuza)->camera->stepy;
			(*yakuza)->camera->side = 1;
		}
		maph = (*yakuza)->camera->mapy;
		mapw = (*yakuza)->camera->mapx;
		if ((*yakuza)->map->map[maph][mapw] == '1')
			hit = 1;
	}
}

// func - 3
void	init_texture(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->texture = malloc(sizeof(t_news_tex));
	if (!(*yakuza)->texture)
	{
		free_map((*yakuza)->map);
		free(yakuza);
		malloc_err();
	}
	(*yakuza)->texture->north = mlx_load_png((*yakuza)->map->wall->north);
	(*yakuza)->texture->south = mlx_load_png((*yakuza)->map->wall->south);
	(*yakuza)->texture->east = mlx_load_png((*yakuza)->map->wall->east);
	(*yakuza)->texture->west = mlx_load_png((*yakuza)->map->wall->west);
	if (!(*yakuza)->texture->north || !(*yakuza)->texture->east
		|| !(*yakuza)->texture->south || !(*yakuza)->texture->west)
	{
		write(2, "Texture not loaded!\n", 21);
		return ;
	}
}

// func - 4
void	setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac)
{
	int		param_len;
	t_map	*map;

	map = NULL;
	param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][param_len - 4], ".cub", 4))
	{
		write(2, "invalid file extention\n", 24);
		exit(1);
	}
	if (setting_map(&map, av, ac) == 1)
		exit(1);
	init_tokugawa_sokoku(&(*yakuza));
	(*yakuza)->map = map;
	init_texture(&(*yakuza));
	init_kumicho(&(*yakuza));
	(*yakuza)->camera = malloc(sizeof(t_camera));
	if (!(*yakuza)->camera)
		malloc_err();
	init_minimap(&(*yakuza));
}

// void	setup_config(t_tokugawa_sokoku **yakuza, char **av, int ac)
// {
// 	int	param_len;
// 	t_map	*map;

// 	param_len = ft_strlen(av[1]);
// 	if (!ft_strnstr(&av[1][param_len - 4], ".cub", 4))
// 	{
// 		write(2, "invalid file extention\n", 25);
// 		exit(1);
// 	}
// 	allocate_map(&map);
// 	if (setting_map(&(*yakuza)->map, av, ac) == 1)
// 		malloc_err();
// 	init_tokugawa_sokoku(&(*yakuza));
// 	(*yakuza)->map = map;
// 	init_texture(&(*yakuza));
// 	init_kumicho(&(*yakuza));
// 	(*yakuza)->camera = malloc(sizeof(t_camera));
// 	if (!(*yakuza)->camera)
// 		malloc_err();
// 	init_minimap(&(*yakuza));
// }

// func - 5
void	allocate_map(t_map **map)
{
	(*map) = malloc(sizeof(t_map));
	if (!*map)
		malloc_err();
	(*map)->wall = malloc(sizeof(t_wall_path));
	if (!(*map)->wall)
		malloc_err();
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->player_count = 0;
	(*map)->map = NULL;
	(*map)->cpy_map = NULL;
	(*map)->floor = NULL;
	(*map)->ceiling = NULL;
}
