/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokugawa_sokoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:24 by modat             #+#    #+#             */
/*   Updated: 2025/09/21 16:04:01 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"
static void draw_vertical_line(mlx_image_t *img, int x, int start, int end, uint32_t color)
{
    // texture here 
    int y;

    y = start;
    while (y <= end)
    {
        if (x >= 0 && x < WIDTH && y >= 0 && y <HEIGHT)
            mlx_put_pixel(img, x, y, color);
        y++;
    }
}

static void raycasting(t_tokugawa_sokoku *yakuza)
{
    for (int x = 0; x < WIDTH; x++)
    {
        // 1. Compute ray direction
        
        double cameraX = 2 * x / (double)WIDTH - 1; // is the representaton of column x in window in math scale [-1, 1]
        double rayDirX = yakuza->kumicho->direction.w + yakuza->kumicho->plane.w * cameraX;
        double rayDirY = yakuza->kumicho->direction.h + yakuza->kumicho->plane.h * cameraX;

        // 2. DDA stepping (simplified example)
        // player in the map
        int mapX = (int)yakuza->kumicho->offset.w;
        int mapY = (int)yakuza->kumicho->offset.h;

        // setp size
        // How far the ray has to go in X or Y before crossing into the next tile(square):
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        double sideDistX;
        double sideDistY;
        int stepX;
        int stepY;

        if (rayDirX < 0)
        { 
            stepX = -1; 
            sideDistX = (yakuza->kumicho->offset.w - mapX) * deltaDistX; 
        }
        else             
        { 
            stepX = 1; 
            sideDistX = (mapX + 1.0 - yakuza->kumicho->offset.w) * deltaDistX; 
        }

        if (rayDirY < 0) 
        { 
            stepY = -1; 
            sideDistY = (yakuza->kumicho->offset.h - mapY) * deltaDistY; 
        }
        else             
        { 
            stepY = 1; 
            sideDistY = (mapY + 1.0 - yakuza->kumicho->offset.h) * deltaDistY; 
        }
        
        int hit = 0;
        int side;
        while (!hit)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (yakuza->map->map[mapY][mapX] == '1')
                hit = 1;
        }

        //3. Calculate distance to wall
        double perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - yakuza->kumicho->offset.w + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - yakuza->kumicho->offset.h + (1 - stepY) / 2) / rayDirY;

        // 4. Line height
        int lineHeight = (int)(HEIGHT / perpWallDist);
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        printf("line height: %d\n", lineHeight);
        uint32_t color = (side == 1) ? 0xAAAAAAFF : 0xFFFFFFFF;

        draw_vertical_line(yakuza->img, x, drawStart, drawEnd, color);
    }
}

// void    side_dis(t_tokugawa_sokoku **yakuza)
// {

//         if ((*yakuza)->camera->ray_dirx < 0)
//         {
//             // moving to left from center -1, 1 edges based on camerax
//             (*yakuza)->camera->stepx = -1;
//             // side_disx = (number of steps from central to player pos on map "double arry") * jump value on x or y scale
//             (*yakuza)->camera->side_disx = ((*yakuza)->kumicho->offset.w - (*yakuza)->camera->mapy) * (*yakuza)->camera->delta_disx;
//             // meaning I moved/shift to left from center that distance. 
//         }
//         else 
//         {
//             (*yakuza)->camera->stepx = 1;
//             (*yakuza)->camera->side_disx = ((*yakuza)->camera->mapx + 1 - (*yakuza)->kumicho->offset.w) * (*yakuza)->camera->delta_disx;
//         }
//         if ((*yakuza)->camera->ray_diry < 0)
//         {
//             // moving to left from center -1, 1 edges based on camerax
//             (*yakuza)->camera->stepy = -1;
//             // side_disx = (number of steps from central to player pos on map "double arry") * jump value on x or y scale
//             (*yakuza)->camera->side_disy = ((*yakuza)->kumicho->offset.h - (*yakuza)->camera->mapy) * (*yakuza)->camera->delta_disy;
//             // meaning I moved/shift to left from center that distance. 
//         }
//         else 
//         {
//             (*yakuza)->camera->stepy = 1;
//             (*yakuza)->camera->side_disy = ((*yakuza)->camera->mapy + 1 - (*yakuza)->kumicho->offset.h) * (*yakuza)->camera->delta_disy;
//         }
        
// }

// void    init_camera(t_tokugawa_sokoku **yakuza, int x)
// {
//     // extract inputs 
//     // 1) math scale of x on window
//     (*yakuza)->camera->camerax = 2 * x / (double)WIDTH - 1;
//     // 2) on which side we are lookig to know where we will shift and later how much I should add/jump for x & y
//     (*yakuza)->camera->ray_dirx = (*yakuza)->kumicho->direction.w + (*yakuza)->kumicho->plane.w * (*yakuza)->camera->camerax;
//     (*yakuza)->camera->ray_diry = (*yakuza)->kumicho->direction.h + (*yakuza)->kumicho->plane.h * (*yakuza)->camera->camerax;
//     // 3) set player position on map >> double arry map == reconvert to int to check map logic is wall or not
//     (*yakuza)->camera->mapx = (int)(*yakuza)->kumicho->offset.w;
//     (*yakuza)->camera->mapy = (int)(*yakuza)->kumicho->offset.w;
//     // 4) to calcolates the amount I need to jump for each x & y
//     (*yakuza)->camera->delta_disx = fabs(1 / (*yakuza)->camera->ray_dirx);
//     (*yakuza)->camera->delta_disy = fabs(1 / (*yakuza)->camera->ray_diry);
//     // 5) to know which side we are shifting to & the amount of shifting
//     side_dis(&(*yakuza));
    
// }

// void    dis_to_wall(t_tokugawa_sokoku **yakuza)
// {
//     // 6) start map logic, measure (side_disx/y, mapx/y, side) then check if it is a wall or not
//     // if not continue add to measurements, if is it a wall go to next step to measure wall distance ...etc
//     int hit;
    
//     hit = 0;
//     (*yakuza)->camera->side = 0;
//     while (!hit) // as long as it a floor = 0
//     {
//         // measure side_disx/y, mapx/y, side >> know which side & player position on map[h][w] & side_dis (number of steps * one step value "jump value")
//         // the mesurements based 
//         if ((*yakuza)->camera->side_disx < (*yakuza)->camera->side_disy)
//         {
//             (*yakuza)->camera->side_disx += (*yakuza)->camera->delta_disx; // on screen scale camerax;
//             (*yakuza)->camera->mapx += (*yakuza)->camera->stepx; // on double array map[h][w]
//             (*yakuza)->camera->side = 0; // we keep looping until hit a wall, last value tells us last floor/ wall first hit on x axis or y axis ? when we check down to calculate the wall dis/tall we need it to draw
//         }
//         else 
//         {
//             (*yakuza)->camera->side_disy += (*yakuza)->camera->delta_disy;
//             (*yakuza)->camera->mapy += (*yakuza)->camera->stepy;
//             (*yakuza)->camera->side = 1;
//         }
//         if ((*yakuza)->map->map[(*yakuza)->camera->mapy][(*yakuza)->camera->mapx] == '1')
//             hit = 1;
//     }
// }

// void    find_wall_height(t_tokugawa_sokoku **yakuza)
// {
//     // 7) find wall height, if we hit a wall on x we use x values if on y , we use y values 
//     // player to wall on map
//     double  player_to_wall_dis;
//     int wall_len;

//     if ((*yakuza)->camera->side == 0) // hit x >> x values
//         player_to_wall_dis = ((*yakuza)->camera->mapx - (*yakuza)->kumicho->offset.w + (1 - (*yakuza)->camera->stepx) / 2) / (*yakuza)->camera->ray_dirx;
//     else    // hit y, y values
//         player_to_wall_dis = ((*yakuza)->camera->mapy - (*yakuza)->kumicho->offset.h + (1 - (*yakuza)->camera->stepy) / 2) / (*yakuza)->camera->ray_dirx; 
    
//     // 8) wall_length_on_win_h
//     wall_len = ((int)HEIGHT / player_to_wall_dis);
//     (*yakuza)->camera->wall_starts = -wall_len / 2 + HEIGHT / 2;
//     if ((*yakuza)->camera->wall_starts < 0)
//         (*yakuza)->camera->wall_starts = 0;
//     (*yakuza)->camera->wall_ends = wall_len / 2 + HEIGHT / 2;
//     if ((*yakuza)->camera->wall_ends > HEIGHT)
//         (*yakuza)->camera->wall_ends = HEIGHT - 1;
// }

// static void    raycasting(t_tokugawa_sokoku **yakuza)
// {
//     int x;

//     x = 0;
//     while (x < WIDTH)
//     {
//         init_camera(&(*yakuza), x);
//         dis_to_wall(&(*yakuza));
//         find_wall_height(&(*yakuza));
//         uint32_t color = ((*yakuza)->camera->side == 1) ? 0xAAAAAAFF : 0xFFFFFFFF;
//         draw_vertical_line((*yakuza)->img, x, (*yakuza)->camera->wall_starts, (*yakuza)->camera->wall_ends, color);
//         x++;
//     }
// }

 void    enter_tokugawa_sokoku(void *land)
{
    t_tokugawa_sokoku *yakuza = (t_tokugawa_sokoku *)land;
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_W))
        forward(yakuza);
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_S))
        backward(yakuza);
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_A))
        left(yakuza);
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_D))
        right(yakuza);
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_LEFT))
        rotate_left(yakuza, ROT_SPEED);
    if (mlx_is_key_down(yakuza->mlx, MLX_KEY_RIGHT))
        rotate_right(yakuza, ROT_SPEED);
    
    draw_background(yakuza->minimap);
    // set_ceiling_floor(&(yakuza));
    raycasting(yakuza);
	minimap(yakuza->minimap, yakuza->map);
}

/*
player info:
1 >> position on map >> translated  on wind
2 >> direction cordinates
3 >> plane coordinates

h w + 0.5
*/