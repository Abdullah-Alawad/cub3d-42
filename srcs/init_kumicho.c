/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kumicho.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:29:35 by marvin            #+#    #+#             */
/*   Updated: 2025/09/20 18:29:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static int	is_direct(char news)
{
	if (news == 'N')
		return (1);
	else if (news == 'S')
		return (1);
	else if (news == 'W')
		return (1);
	else if (news == 'E')
		return (1);
	return (0);
}

// func - 2
static void	set_dir(t_tokugawa_sokoku **yakuza, char news)
{
	if (news == 'N')
	{
		(*yakuza)->kumicho->dir = 'N';
		(*yakuza)->kumicho->direction.w = 0.0;
		(*yakuza)->kumicho->direction.h = -1.0;
	}
	else if (news == 'S')
	{
		(*yakuza)->kumicho->dir = 'S';
		(*yakuza)->kumicho->direction.w = 0.0;
		(*yakuza)->kumicho->direction.h = 1.0;
	}
	else if (news == 'W')
	{
		(*yakuza)->kumicho->dir = 'W';
		(*yakuza)->kumicho->direction.w = -1.0;
		(*yakuza)->kumicho->direction.h = 0.0;
	}
	else if (news == 'E')
	{
		(*yakuza)->kumicho->dir = 'E';
		(*yakuza)->kumicho->direction.w = 1.0;
		(*yakuza)->kumicho->direction.h = 0.0;
	}
}

// func - 3
static void	set_plane(t_tokugawa_sokoku **yakuza, char news)
{
	if (news == 'N')
	{
		(*yakuza)->kumicho->plane.w = 0.66;
		(*yakuza)->kumicho->plane.h = 0;
	}
	else if (news == 'S')
	{
		(*yakuza)->kumicho->plane.w = -0.66;
		(*yakuza)->kumicho->plane.h = 0;
	}
	else if (news == 'W')
	{
		(*yakuza)->kumicho->plane.w = 0.0;
		(*yakuza)->kumicho->plane.h = 0.66;
	}
	else if (news == 'E')
	{
		(*yakuza)->kumicho->plane.w = 0.0;
		(*yakuza)->kumicho->plane.h = -0.66;
	}
}

// func - 4
void	init_kumicho_2(t_tokugawa_sokoku **yakuza)
{
	int	w;
	int	h;

	h = 0;
	while ((*yakuza)->map->map[h])
	{
		w = 0;
		while ((*yakuza)->map->map[h][w])
		{
			if (is_direct((*yakuza)->map->map[h][w]))
			{
				(*yakuza)->kumicho->offset.w = w + 0.5;
				(*yakuza)->kumicho->offset.h = h + 0.5;
				set_dir(&(*yakuza), (*yakuza)->map->map[h][w]);
				set_plane(&(*yakuza), (*yakuza)->map->map[h][w]);
			}
			w++;
		}
		h++;
	}
}
