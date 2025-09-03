/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/03 21:53:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void     init_color(t_rgb *(*floor), t_rgb *(*ceiling))
{
    (*floor) = malloc(sizeof(t_rgb));
    if (!(floor))
        return ;
    (*ceiling) = malloc(sizeof(t_rgb));
     if (!(floor))
        return ;
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
    // draw 
    // raycasting
    // rending 
	mlx_loop(mlx);
    
    return (0);
}