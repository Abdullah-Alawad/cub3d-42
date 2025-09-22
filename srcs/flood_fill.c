/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:16:01 by modat             #+#    #+#             */
/*   Updated: 2025/09/22 15:18:14 by modat            ###   ########.fr       */
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
			line_no--;
			while (line_no >= 0)
				free((*map)->cpy_map[line_no--]);
			malloc_err();
		}
		line_no++;
	}
}

// func - 2

int flood_fill(t_map *map, int py, int px)
{
    size_t rowlen;
    char  c;

    /* 1) row / col out of the map -> leak */
    if (py < 0 || py >= map->height)
        return 0;

    if (!map->cpy_map[py]) /* safety */
        return 0;

    rowlen = ft_strlen(map->cpy_map[py]);
    if (px < 0 || (size_t)px >= rowlen)
        return 0;

    c = map->cpy_map[py][px];

    /* 2) wall or already visited -> ok (stop) */
    if (c == '1' || c == 'X')
        return 1;

    /* 3) explicit invalid chars -> leak */
    if (c == ' ' || c == '\0')
        return 0;

    /* 4) if this non-wall cell sits on the outer border -> leak */
    if (py == 0 || py == map->height - 1 || px == 0 || (size_t)px == rowlen - 1)
        return 0;

    /* 5) mark visited */
    map->cpy_map[py][px] = 'X';

    /* 6) recurse in 8 directions (diagonals included) */
    if (!flood_fill(map, py - 1, px))         return 0;
    if (!flood_fill(map, py + 1, px))         return 0;
    if (!flood_fill(map, py,     px - 1))     return 0;
    if (!flood_fill(map, py,     px + 1))     return 0;
    if (!flood_fill(map, py - 1, px - 1))     return 0;
    if (!flood_fill(map, py - 1, px + 1))     return 0;
    if (!flood_fill(map, py + 1, px - 1))     return 0;
    if (!flood_fill(map, py + 1, px + 1))     return 0;

    return 1;
}

// func - 3
void    save_player_positions(t_map **map)
{
    int y;
    int x;

    y = 0;
    while (y < (*map)->height)
    {
        x = 0;
        while (x < (*map)->width)
        {
            char c = (*map)->cpy_map[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                (*map)->py = y;
                (*map)->px = x;
            }
            x++;
        }
        y++;
    }
}

