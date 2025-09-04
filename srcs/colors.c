/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:05:54 by modat             #+#    #+#             */
/*   Updated: 2025/09/04 14:51:34 by modat            ###   ########.fr       */
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
    (*floor)->r = 15;
    (*floor)->g = 6;
    (*floor)->b = 40;

    (*ceiling)->r = 171;
    (*ceiling)->g = 154;
    (*ceiling)->b = 137;
}

// func - 2
int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
