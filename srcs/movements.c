/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:16:43 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 08:03:57 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yakuza.h"

// func - 1
void	forward(t_tokugawa_sokoku *yakuza)
{
	t_coords	new_offset;
	int			w;
	int			h;
	int			w2;
	int			h2;

	new_offset.w = yakuza->kumicho->offset.w + (yakuza->kumicho->direction.w
			* MOVE_SPEED);
	new_offset.h = yakuza->kumicho->offset.h + (yakuza->kumicho->direction.h
			* MOVE_SPEED);
	if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
	{
		w = (int)yakuza->kumicho->offset.w;
		h = (int)yakuza->kumicho->offset.h;
		yakuza->map->map[h][w] = '0';
		yakuza->kumicho->offset.w = new_offset.w;
		yakuza->kumicho->offset.h = new_offset.h;
		w2 = (int)new_offset.w;
		h2 = (int)new_offset.h;
		yakuza->map->map[h2][w2] = yakuza->map->player_direction;
	}
}

// func - 2
void	backward(t_tokugawa_sokoku *yakuza)
{
	t_coords	new_offset;
	int			w;
	int			h;
	int			w2;
	int			h2;

	new_offset.w = yakuza->kumicho->offset.w - (yakuza->kumicho->direction.w
			* MOVE_SPEED);
	new_offset.h = yakuza->kumicho->offset.h - (yakuza->kumicho->direction.h
			* MOVE_SPEED);
	if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
	{
		w = (int)yakuza->kumicho->offset.w;
		h = (int)yakuza->kumicho->offset.h;
		yakuza->map->map[h][w] = '0';
		yakuza->kumicho->offset.w = new_offset.w;
		yakuza->kumicho->offset.h = new_offset.h;
		w2 = (int)new_offset.w;
		h2 = (int)new_offset.h;
		yakuza->map->map[h2][w2] = yakuza->map->player_direction;
	}
}

// func - 3
void	left(t_tokugawa_sokoku *yakuza)
{
	t_coords	new_offset;
	int			w;
	int			h;
	int			w2;
	int			h2;

	new_offset.w = yakuza->kumicho->offset.w - (yakuza->kumicho->plane.w
			* MOVE_SPEED);
	new_offset.h = yakuza->kumicho->offset.h - (yakuza->kumicho->plane.h
			* MOVE_SPEED);
	if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
	{
		w = (int)yakuza->kumicho->offset.w;
		h = (int)yakuza->kumicho->offset.h;
		yakuza->map->map[h][w] = '0';
		yakuza->kumicho->offset.w = new_offset.w;
		yakuza->kumicho->offset.h = new_offset.h;
		w2 = (int)new_offset.w;
		h2 = (int)new_offset.h;
		yakuza->map->map[h2][w2] = yakuza->map->player_direction;
	}
}

// func - 4
void	right(t_tokugawa_sokoku *yakuza)
{
	t_coords	new_offset;
	int			w;
	int			h;
	int			w2;
	int			h2;

	new_offset.w = yakuza->kumicho->offset.w + (yakuza->kumicho->plane.w
			* MOVE_SPEED);
	new_offset.h = yakuza->kumicho->offset.h + (yakuza->kumicho->plane.h
			* MOVE_SPEED);
	if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
	{
		w = (int)yakuza->kumicho->offset.w;
		h = (int)yakuza->kumicho->offset.h;
		yakuza->map->map[h][w] = '0';
		yakuza->kumicho->offset.w = new_offset.w;
		yakuza->kumicho->offset.h = new_offset.h;
		w2 = (int)new_offset.w;
		h2 = (int)new_offset.h;
		yakuza->map->map[h2][w2] = yakuza->map->player_direction;
	}
}
