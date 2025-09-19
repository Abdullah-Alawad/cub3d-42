/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/19 09:15:19 by marvin           ###   ########.fr       */
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