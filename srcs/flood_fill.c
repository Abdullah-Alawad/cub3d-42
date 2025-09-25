/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:16:01 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 10:02:23 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	copy_map(t_map **map)
{
	int	line_no;

	line_no = 0;
	(*map)->cpy_map = malloc(sizeof(char *) * ((*map)->height + 1));
	if (!(*map)->cpy_map)
		malloc_err();
	(*map)->cpy_map[(*map)->height] = NULL;
	while (line_no < (*map)->height)
	{
		(*map)->cpy_map[line_no] = ft_strdup((*map)->map[line_no]);
		if (!(*map)->cpy_map[line_no])
		{
			while (line_no > 0)
				free((*map)->cpy_map[--line_no]);
			free((*map)->cpy_map);
		}
		line_no++;
	}
}

// func - 2
static int	check_flood(t_map *map, int py, int px)
{
	if (!flood_fill(map, py - 1, px))
		return (0);
	if (!flood_fill(map, py + 1, px))
		return (0);
	if (!flood_fill(map, py, px - 1))
		return (0);
	if (!flood_fill(map, py, px + 1))
		return (0);
	if (!flood_fill(map, py - 1, px - 1))
		return (0);
	if (!flood_fill(map, py - 1, px + 1))
		return (0);
	if (!flood_fill(map, py + 1, px - 1))
		return (0);
	if (!flood_fill(map, py + 1, px + 1))
		return (0);
	return (1);
}

int	flood_fill(t_map *map, int py, int px)
{
	size_t	rowlen;
	char	c;

	if (py < 0 || py >= map->height)
		return (0);
	if (!map->cpy_map[py])
		return (0);
	rowlen = ft_strlen(map->cpy_map[py]);
	if (px < 0 || (size_t)px >= rowlen)
		return (0);
	c = map->cpy_map[py][px];
	if (c == '1' || c == 'X')
		return (1);
	if (c == ' ' || c == '\0')
		return (0);
	if (py == 0 || py == map->height - 1 || px == 0 || (size_t)px == rowlen - 1)
		return (0);
	map->cpy_map[py][px] = 'X';
	return (check_flood(map, py, px));
}

// func - 3
int	save_player_positions(t_map **map)
{
	int		y;
	int		x;
	int		width;
	char	c;

	y = 0;
	while (y < (*map)->height)
	{
		x = 0;
		width = ft_strlen((*map)->cpy_map[y]);
		while (x < width)
		{
			c = (*map)->cpy_map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				(*map)->py = y;
				(*map)->px = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// func - 4
int	open_map(int *fd, char **av, int ac)
{
	if (ac != 2)
		return (1);
	(*fd) = open(av[1], O_RDONLY);
	if ((*fd) == -1)
	{
		perror("open");
		return (1);
	}
	return (0);
}
