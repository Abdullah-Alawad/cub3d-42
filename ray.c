// static void raycasting(t_tokugawa_sokoku *yakuza)
// {
//     for (int x = 0; x < WIDTH; x++)
//     {
//         // 1. Compute ray direction
        
//         double cameraX = 2 * x / (double)WIDTH - 1; // is the representaton of column x in window in math scale [-1, 1]
//         double rayDirX = yakuza->kumicho->direction.w + yakuza->kumicho->plane.w * cameraX;
//         double rayDirY = yakuza->kumicho->direction.h + yakuza->kumicho->plane.h * cameraX;

//         // 2. DDA stepping (simplified example)
//         // player in the map
//         int mapX = (int)yakuza->kumicho->offset.w;
//         int mapY = (int)yakuza->kumicho->offset.h;

//         // setp size
//         // How far the ray has to go in X or Y before crossing into the next tile(square):
//         double deltaDistX = fabs(1 / rayDirX);
//         double deltaDistY = fabs(1 / rayDirY);

//         double sideDistX;
//         double sideDistY;
//         int stepX;
//         int stepY;

//         if (rayDirX < 0)
//         { 
//             stepX = -1; 
//             sideDistX = (yakuza->kumicho->offset.w - mapX) * deltaDistX; 
//         }
//         else             
//         { 
//             stepX = 1; 
//             sideDistX = (mapX + 1.0 - yakuza->kumicho->offset.w) * deltaDistX; 
//         }

//         if (rayDirY < 0) 
//         { 
//             stepY = -1; 
//             sideDistY = (yakuza->kumicho->offset.h - mapY) * deltaDistY; 
//         }
//         else             
//         { 
//             stepY = 1; 
//             sideDistY = (mapY + 1.0 - yakuza->kumicho->offset.h) * deltaDistY; 
//         }
        
//         int hit = 0;
//         int side;
//         while (!hit)
//         {
//             if (sideDistX < sideDistY)
//             {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             }
//             else
//             {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             if (yakuza->map->map[mapY][mapX] == '1')
//                 hit = 1;
//         }

//         //3. Calculate distance to wall
//         double perpWallDist;
//         if (side == 0)
//             perpWallDist = (mapX - yakuza->kumicho->offset.w + (1 - stepX) / 2) / rayDirX;
//         else
//             perpWallDist = (mapY - yakuza->kumicho->offset.h + (1 - stepY) / 2) / rayDirY;

//         // 4. Line height
//         int lineHeight = (int)(HEIGHT / perpWallDist);
//         int drawStart = -lineHeight / 2 + HEIGHT / 2;
//         if (drawStart < 0)
//             drawStart = 0;
//         int drawEnd = lineHeight / 2 + HEIGHT / 2;
//         if (drawEnd >= HEIGHT)
//             drawEnd = HEIGHT - 1;

//         printf("line height: %d\n", lineHeight);
//         uint32_t color = (side == 1) ? 0xAAAAAAFF : 0xFFFFFFFF;

//         draw_vertical_line(yakuza->img, x, drawStart, drawEnd, color);
//     }
// }
