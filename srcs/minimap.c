/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:53:20 by modat             #+#    #+#             */
/*   Updated: 2025/09/12 17:50:02 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

static void    draw(t_minimap **minimap, uint32_t color, char fw)
{   
    int counterH;
    int counterW;
    
    counterH = 0;
    if ((*minimap)->h <  MINI_HEIGHT) // big loop
    {
        (*minimap)->w = 0;
        if ((*minimap)->w  < MINI_WIDTH) // big loop
        {
            while ((counterH < (MINI_HEIGHT * 4)/10)) // small loop
            {
                // (*minimap)->w = 0;
                counterW = 0;
                while ( counterW < (MINI_WIDTH * 4)/10) // smal loop
                {
                    if (fw == '1')
                        mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
                    else if (fw == '0')
                        mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
                    else
                        mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
                    (*minimap)->w++;
                    counterW++;
                    if (counterW == (MINI_WIDTH * 4)/10)
                        break ;
                    }
                (*minimap)->h++;
                counterH++;
                if (counterH == (MINI_HEIGHT * 4)/10)
                    break ;
                }
            continue ;

                // break ;
        // (*minimap)->w++;
            }
    // (*minimap)->h++;
            continue ;
        }
    }
    // counterH = 0;
    // while ((*minimap)->h < 20/3)
    // {
    //     (*minimap)->w = 0;
    //     counterW = 0;
    //     while ((*minimap)->w < 20/3)
    //     {
    //         if (fw == '1')
    //             mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
    //         else if (fw == '0')
    //             mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
    //         else
    //             mlx_put_pixel((*minimap)->miniimg, (*minimap)->w, (*minimap)->h, color);
    //         (*minimap)->w++;
    //         if (counterW == 20)
    //             break ;
    //     }
    //     (*minimap)->h++;
    //     counterH++;
    //     if (counterH == 20)
    //         break ;
    // }
// }

void    minimap(t_minimap *minimap, char **map)
{
    int h;
    int w;

    h = 0;
    while (map[h])
    {
        w = 0;
        while (map[h][w])
        {
            printf("w: %d, h: %d", minimap->w, minimap->h);
            if (map[h][w] == '1')
                draw(&minimap, 0xBBBBBBBB, map[h][w]);
            if (map[h][w] == '0')
                draw(&minimap, 0x00000000, map[h][w]);
            else if (map[h][w] == ' ')
                draw(&minimap, 0xDDDDDDDD, map[h][w]);
            w++;
            // minimap->w++;
        }
        h++;
        printf("\n");
        // minimap->h++;
    }
}

// func - 2
