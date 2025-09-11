/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/11 17:16:36 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

// void 	beg_end_one(char *map)
// {
// 	int w;

// 	w = 0;
// 	while (map[w] == ' ' || map[w] == '\t')
// 		w++;
// 	while (map[w])
// 	{
// 		if (map[w] == '1')
// 		{
// 			w++;
// 			if (map[w] == 'N')
// 				w++;
// 			while (map[w] == '0')
// 				w++;
// 			if (map[w] != '1')
// 			{
// 				perror("unclosed map");
// 				exit_free();
// 			}			
// 		}
// 		w++;
// 	}
// }

// void	is_top_bottom_one(char *map)
// {
// 	int w;
	
// 	w = 0;
// 	while (map[w] == ' ' || map[w] == '\t')
// 			w++;
// 	while (map[w])
// 	{
// 		if (map[w] != 1 || map[w] != ' ')
// 		{
// 			perror("unclosed map");
// 			exit_free();
// 		}
// 		w++;
// 	}
// }	

// void 	up_down(char **map)
// {
// 	while (map[h])
// 	{
// 		if (map[h][w] == '0')
// 		{
// 		if (map[h -1][w] == ' ')
// 		{
// 			perror("unclosed map");
// 			exit_free();
// 		}
// 			w++;
// 		}	
// 	}
// }

// void 	map_check(char **map)
// {
// 	while (map[h])
// 	{
// 		is_top_bottom_one(map[0]);
// 		is_top_bottom_one(map[map->height - 1]);
// 		is_beg_end_one(map[h]);
// 		h++;
// 	}
// 	up_down(map);
// }
