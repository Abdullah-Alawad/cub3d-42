/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/20 18:46:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void    enter_tokugawa_sokoku(void *land)
{
    t_tokugawa_sokoku *yakuza = (t_tokugawa_sokoku *)land;
    draw_background(yakuza->minimap);
	map(yakuza);
	minimap(yakuza->minimap, yakuza->map);
    // usleep(5000);
}

/*
player info:
1 >> position on map >> translated  on wind
2 >> direction cordinates
3 >> plane coordinates

h w + 0.5
*/