/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:16:43 by modat             #+#    #+#             */
/*   Updated: 2025/09/21 09:58:56 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yakuza.h"

// func - 1
void    forward(t_tokugawa_sokoku *yakuza)
{
    t_coords new_offset;

    new_offset.w = yakuza->kumicho->offset.w + (yakuza->kumicho->direction.w * MOVE_SPEED);
    new_offset.h = yakuza->kumicho->offset.h + (yakuza->kumicho->direction.h * MOVE_SPEED);
    if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
    {
        yakuza->map->map[(int)yakuza->kumicho->offset.h][(int)yakuza->kumicho->offset.w] = '0';
        yakuza->kumicho->offset.w = new_offset.w;
        yakuza->kumicho->offset.h = new_offset.h;
        yakuza->map->map[(int)new_offset.h][(int)new_offset.w] = yakuza->map->player_direction;
    }
}

// func - 2
void    backward(t_tokugawa_sokoku *yakuza)
{
    t_coords new_offset;

    new_offset.w = yakuza->kumicho->offset.w - (yakuza->kumicho->direction.w * MOVE_SPEED);
    new_offset.h = yakuza->kumicho->offset.h - (yakuza->kumicho->direction.h * MOVE_SPEED);
    if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
    {
        yakuza->map->map[(int)yakuza->kumicho->offset.h][(int)yakuza->kumicho->offset.w] = '0';
        yakuza->kumicho->offset.w = new_offset.w;
        yakuza->kumicho->offset.h = new_offset.h;
        yakuza->map->map[(int)new_offset.h][(int)new_offset.w] = yakuza->map->player_direction;
    }
}

// func - 3
void    left(t_tokugawa_sokoku *yakuza)
{
    t_coords new_offset;

    new_offset.w = yakuza->kumicho->offset.w - (yakuza->kumicho->plane.w * MOVE_SPEED);
    new_offset.h = yakuza->kumicho->offset.h - (yakuza->kumicho->plane.h * MOVE_SPEED);
    if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
    {
        yakuza->map->map[(int)yakuza->kumicho->offset.h][(int)yakuza->kumicho->offset.w] = '0';
        yakuza->kumicho->offset.w = new_offset.w;
        yakuza->kumicho->offset.h = new_offset.h;
        yakuza->map->map[(int)new_offset.h][(int)new_offset.w] = yakuza->map->player_direction;
    }
}

// func - 4
void    right(t_tokugawa_sokoku *yakuza)
{
    t_coords new_offset;

    new_offset.w = yakuza->kumicho->offset.w + (yakuza->kumicho->plane.w * MOVE_SPEED);
    new_offset.h = yakuza->kumicho->offset.h + (yakuza->kumicho->plane.h * MOVE_SPEED);
    if (yakuza->map->map[(int)new_offset.h][(int)new_offset.w] != '1')
    {
        yakuza->map->map[(int)yakuza->kumicho->offset.h][(int)yakuza->kumicho->offset.w] = '0';
        yakuza->kumicho->offset.w = new_offset.w;
        yakuza->kumicho->offset.h = new_offset.h;
        yakuza->map->map[(int)new_offset.h][(int)new_offset.w] = yakuza->map->player_direction;
    }
}
