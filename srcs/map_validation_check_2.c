/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_check_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:37:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 23:20:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static void	is_beg_end_one(char *map)
{
	char	*tmp;
	int		len;

	tmp = ft_strtrim(map, " \n\t");
	len = ft_strlen(tmp);
	if (tmp[0] != '1' || tmp[len - 1] != '1')
	{
		perror("unclosd map: beg_end");
		exit(1);
	}
	free(tmp);
}

// func - 2
static void	is_top_bottom_one(char *map)
{
	int	w;

	w = 0;
	while (map[w] == ' ' || map[w] == '\t')
		w++;
	while (map[w])
	{
		if (map[w] == ' ')
			w++;
		else if (map[w] == '1')
			w++;
		else
		{
			perror("unclosed map top_bo");
			exit(1);
		}
	}
}

// func - 3
static void	up_down(char **map, int height)
{
	int	h;
	int	w;
	int	len;

	h = 1;
	len = 0;
	while (h < (height - 1))
	{
		w = 0;
		len = ft_strlen(map[h]);
		while (w < len)
		{
			if (map[h][w] == '0' || map[h][w] == 'N' || map[h][w] == 'S'
				|| map[h][w] == 'E' || map[h][w] == 'W')
			{
				if ((map[h - 1][w] == ' ') || (map[h + 1][w] == ' '))
				{
					perror("unclosed map up_daown");
					exit(1);
				}
				if ((map[h - 1][w] == '\0') || (map[h + 1][w] == '\0'))
				{
					perror("unclosed map up_daown");
					exit(1);
				}
			}
			w++;
		}
		h++;
	}
}

// func - 4
void	map_check(char **map, int height)
{
	int	h;

	h = 1;
	is_top_bottom_one(map[0]);
	is_top_bottom_one(map[height - 1]);
	while (h < (height - 1))
	{
		is_beg_end_one(map[h]);
		h++;
	}
	up_down(map, height);
}
