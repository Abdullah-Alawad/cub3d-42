/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/19 13:22:06 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void    enter_tokugawa_sokoku(void *land)
{
    t_tokugawa_sokoku *yakuza = (t_tokugawa_sokoku *)land;
    draw_background(yakuza->minimap);
	// minimap(yakuza->minimap, yakuza->map);
	map(yakuza);
}

/*
player info:
1 >> position on map >> translated  on wind
2 >> direction cordinates
3 >> plane coordinates

h w + 0.5
*/