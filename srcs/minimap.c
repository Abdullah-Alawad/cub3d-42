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
static void draw(t_minimap *minimap, uint32_t color, t_ints start, t_ints p)

{
    int y;
    int x;
    int px;
    int py;

    y = 0;
    while (y < p.h)
    {
        x = 0;
        while (x < p.w)
        {
            px = start.w + x;
            py = start.h + y;
            if (px >= 0 && px < MINI_WIDTH && py >= 0 && py < MINI_HEIGHT)
            {
                mlx_put_pixel(minimap->miniimg, px, py, color);
            }
            x++;
        }
        y++;
    }
}

// func - 2
void minimap(t_minimap *minimap, t_map *map)
{
    t_ints  cell;
    t_ints  start;
    int     h;
    int     w;
    uint32_t color;

    cell.w = MINI_WIDTH / map->width;
    cell.h = MINI_HEIGHT / map->height;
    h = 0;
    while (h < map->height)
    {
        w = 0;
        while (w < map->width)
        {
            color = 0x00000033; // default black
            if (map->map[h][w] == '1')
                color = 0xBBDDFBBB; // wall
            else if (map->map[h][w] == '0')
                color = 0xFFFFFFFF; // floor
            else if (map->map[h][w] == 'N')
                color = 0xFF0000FF; // player
            start.w = w * cell.w;
            start.h = h * cell.h;
            draw(minimap, color, start, cell);
            w++;
        }
        h++;
    }   
}

// func - 1
// static void    draw(t_minimap **minimap, uint32_t color, float ph, float pw)
// {
//     float w;
//     float h;
//     float wCopy = (*minimap)->w;
//     float hCopy = (*minimap)->h;
//     h = 0.0;
//     while ((float)h < ph)
//     {
//         wCopy = (*minimap)->w;
//         w = 0.0;
//         while ((float)w < pw)
//         {
//             mlx_put_pixel((*minimap)->miniimg, wCopy, hCopy, color);
//             w++;
//             wCopy++;
//         }
//         h++;
//         hCopy++;
//     }
// }

// // func - 2
// void    minimap(t_minimap *minimap, t_map *map)
// {
//     int h;
//     int w;
//     float pixelSizeW = (float)MINI_WIDTH / map->width;
//     float pixelSizeH = (float)MINI_HEIGHT / map->height;
//     h = 0;
//    minimap->h = 0.0;
//     while (map->map[h])
//     {
//       minimap->w = 0.0;
//         w = 0;
//         while (map->map[h][w])
//         {
//             if (map->map[h][w] == '1')
//                 draw(&minimap, 0xBBDDFBBB, pixelSizeW, pixelSizeH);
//             else if (map->map[h][w] == '0')
//                 draw(&minimap, 0xFFFFFFFF, pixelSizeW, pixelSizeH);
//             else if (map->map[h][w] == 'N')
//                 draw(&minimap, 0xFF0000FF, pixelSizeW, pixelSizeH);
//             minimap->w += pixelSizeW;
//             w++;
//         }
//         minimap->h += pixelSizeH;
//         h++;
//     }
// }

