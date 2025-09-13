/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:17:46 by modat             #+#    #+#             */
/*   Updated: 2025/09/13 11:59:52 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yakuza.h"

// func - 1
void    rotate_right(t_tokugawa_sokoku *yakuza, double rotation_speed)
{
    double  old_dir_w;
    double  old_plane_w;

    old_dir_w = yakuza->kumicho->direction.w;
    old_plane_w = yakuza->kumicho->plane.w;
    
    yakuza->kumicho->direction.w = (yakuza->kumicho->direction.w * cos(-rotation_speed))
            - (yakuza->kumicho->direction.h * sin(-rotation_speed));
    yakuza->kumicho->direction.h = (old_dir_w * sin(-rotation_speed))
            - (yakuza->kumicho->direction.h * cos(-rotation_speed));

    yakuza->kumicho->plane.w = (yakuza->kumicho->plane.w * cos(-rotation_speed))
            - (yakuza->kumicho->plane.h * sin(-rotation_speed));
    yakuza->kumicho->plane.h = (old_plane_w * sin(-rotation_speed))
        - (yakuza->kumicho->plane.h * cos(-rotation_speed));
}

// func - 2
void    rotate_left(t_tokugawa_sokoku *yakuza, double rotation_speed)
{
    double  old_dir_w;
    double  old_plane_w;

    old_dir_w = yakuza->kumicho->direction.w;
    old_plane_w = yakuza->kumicho->plane.w;
    
    yakuza->kumicho->direction.w = (yakuza->kumicho->direction.w * cos(rotation_speed))
            - (yakuza->kumicho->direction.h * sin(rotation_speed));
    yakuza->kumicho->direction.h = (old_dir_w * sin(rotation_speed))
            - (yakuza->kumicho->direction.h * cos(rotation_speed));

    yakuza->kumicho->plane.w = (yakuza->kumicho->plane.w * cos(rotation_speed))
            - (yakuza->kumicho->plane.h * sin(rotation_speed));
    yakuza->kumicho->plane.h = (old_plane_w * sin(rotation_speed))
        - (yakuza->kumicho->plane.h * cos(rotation_speed));
}