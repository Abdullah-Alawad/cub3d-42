/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/02 12:11:04 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void     init_color(t_rgb *(*floor), t_rgb *(*ceiling))
{
    (*floor) = malloc(sizeof(t_rgb));
    (*ceiling) = malloc(sizeof(t_rgb));
    (*floor)->r = 15;
    (*floor)->g = 6;
    (*floor)->b = 40;

    (*ceiling)->r = 171;
    (*ceiling)->g = 154;
    (*ceiling)->b = 137;
}


void	init_mlx(void    **mlx, void  **win)
{
	(*mlx) = mlx_init();
	if (!(*mlx))
		return ;
	(*win) = mlx_new_window((*mlx), WIDTH, HEIGHT, "YAKUZA");
	if (!(*win))
		return ;

}


int     main(void)
{
    t_rgb   *floor = NULL;
    t_rgb   *ceiling = NULL;
    void		*mlx = NULL;
	void		*win = NULL;
    
    init_color(&floor, &ceiling);
    init_mlx(&mlx, &win);
    mlx_hook(win, CLOSE, 0, close_win, mlx);
    mlx_hook(win, 2, 1, keypress_hook, mlx);
    // mlx_mouse_hook(fractol->win, mouse_hook, mlx);
    // mlx_key_hook(fractol->win, arrow_keys, mlx);
    // mlx_loop_hook(fractol->mlx, fractal_rendering, fractol);
	mlx_loop(mlx);
    
    return (0);
}