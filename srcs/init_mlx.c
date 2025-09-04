/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:07:17 by modat             #+#    #+#             */
/*   Updated: 2025/09/04 15:05:44 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func -1
void	init_mlx(mlx_t    **mlx)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	(*mlx) = mlx_init(WIDTH, HEIGHT, "YAKUZA", true);
	if (!(*mlx))
	{
        strerror(mlx_errno);
        return ;
    }
}

// func - 2
void	draw_img(mlx_t *mlx, t_rgb *draw, mlx_image_t *img, char fc)
{
		// Create and display the image.
	if (fc == 'c')
	{
		mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT / 2);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			return(1);
	}
	else if (fc == 'f')
	{
		mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
		int upper = 0;
		if (!img || (mlx_image_to_window(mlx, img, 0, HEIGHT / 2) < 0))
			return(1);
	}
    int x = 0;
    int y = 0;
	// Even after the image is being displayed, we can still modify the buffer.
	while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            mlx_put_pixel(img, x, y, rgb(draw->r, draw->g, draw->b));
            y++;
        }
        x++;        
    }
}

// func - 3
void 	set_ceiling_floor(mlx_t *mlx, t_rgb *floor, t_rgb *ceiling, mlx_image_t *img)
{

}

