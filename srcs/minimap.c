/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:53:20 by modat             #+#    #+#             */
/*   Updated: 2025/09/21 09:56:34 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static void    draw(t_minimap **minimap, uint32_t color, float ph, float pw)
{
    float w;
    float h;
    float wCopy = (*minimap)->w;
    float hCopy = (*minimap)->h;
    h = 0.0;
    while ((float)h < ph)
    {
        wCopy = (*minimap)->w;
        w = 0.0;
        while ((float)w < pw)
        {
            mlx_put_pixel((*minimap)->miniimg, wCopy, hCopy, color);
            w++;
            wCopy++;
        }
        h++;
        hCopy++;
    }
}

// func - 2
void    minimap(t_minimap *minimap, t_map *map)
{
    int h;
    int w;
    float pixelSizeW = (float)MINI_WIDTH / map->width;
    float pixelSizeH = (float)MINI_HEIGHT / map->height;
    h = 0;
   minimap->h = 0.0;
    while (map->map[h])
    {
      minimap->w = 0.0;
        w = 0;
        while (map->map[h][w])
        {
            if (map->map[h][w] == '1')
                draw(&minimap, 0xBBDDFBBB, pixelSizeW, pixelSizeH);
            else if (map->map[h][w] == '0')
                draw(&minimap, 0xFFFFFFFF, pixelSizeW, pixelSizeH);
            else if (map->map[h][w] == 'N')
                draw(&minimap, 0xFF0000FF, pixelSizeW, pixelSizeH);
            minimap->w += pixelSizeW;
            w++;
        }
        minimap->h += pixelSizeH;
        h++;
    }
}

