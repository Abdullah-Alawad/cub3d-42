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
// void	copy_map(t_map **map)
// {
// 	int	line_no;

// 	line_no = 0;
// 	(*map)->cpy_map = malloc(sizeof(char *) * ((*map)->height + 1));
// 	if (!(*map)->cpy_map)
// 		malloc_err();
// 	(*map)->cpy_map[(*map)->height] = NULL;
// 	while (line_no < (*map)->height)
// 	{
// 		(*map)->cpy_map[line_no] = ft_strdup((*map)->map[line_no]);
// 		if (!(*map)->cpy_map[line_no])
// 		{
// 			line_no--;
// 			while (line_no >= 0)
// 				free((*map)->cpy_map[line_no--]);
// 			malloc_err();
// 		}
// 		line_no++;
// 	}
// }

// func - 2
// void	flood_fill(t_tokugawa_sokoku *yakuza, int py, int px)
// {
// 	if (py < 0 || px < 0 || py > (game->y - 1) || px > (game->x - 1))
// 		return ;
// 	if (game->cpy_map[py][px] == '1')
// 		return ;
// 	if (game->cpy_map[py][px] == 'E')
// 		game->is_solvable = 1;
// 	game->cpy_map[py][px] = '1';
// 	flood_fill_e(game, py - 1, px);
// 	flood_fill_e(game, py + 1, px);
// 	flood_fill_e(game, py, px - 1);
// 	flood_fill_e(game, py, px + 1);
// }