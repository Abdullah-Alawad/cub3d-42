/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/07 12:06:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void     init_color(t_rgb *(*floor), t_rgb *(*ceiling))
{
    (*floor) = malloc(sizeof(t_rgb));
    if (!(floor))
        return ;
    (*ceiling) = malloc(sizeof(t_rgb));
     if (!(floor))
        return ;
    (*floor)->r = 139;
    (*floor)->g = 69;
    (*floor)->b = 19;

    (*ceiling)->r = 255;
    (*ceiling)->g = 244;
    (*ceiling)->b = 145;
}

// func - 2
int	rgb(int r, int g, int b)
{
	// return ((r << 16) | (g << 8) | b);
	return ((r) | (g) | b);
}
