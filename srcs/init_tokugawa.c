/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokugawa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:07:17 by modat             #+#    #+#             */
/*   Updated: 2025/09/19 16:11:46 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func -1
static void	init_mlx(mlx_t **mlx)
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
void 	init_minimap(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->minimap = malloc(sizeof(t_minimap));
	if (!(*yakuza)->minimap)
		malloc_err();
	(*yakuza)->minimap->h = 0;
	(*yakuza)->minimap->w = 0;
	(*yakuza)->minimap->miniimg = mlx_new_image((*yakuza)->mlx, MINI_WIDTH , MINI_HEIGHT);
    if (!(*yakuza)->minimap->miniimg || (mlx_image_to_window((*yakuza)->mlx, (*yakuza)->minimap->miniimg, 20, 20) < 0))
		return ;
}

// func - 3
static void 	init_mouse(t_mouse **mouse, mlx_t *mlx)
{
	(*mouse) = malloc(sizeof(t_mouse));
	if (!(*mouse))
		malloc_err();
	mlx_get_mouse_pos(mlx, &(*mouse)->x, &(*mouse)->y);
}

int	is_direct(char news)
{
	int	i;

	i = 0;
	if (news == 'N')
		return (1);
	else if (news == 'S')
		return (1);
	else if (news == 'W')
		return (1);
	else if (news == 'E')
		return (1);
	return (0);
}

void 	set_dir(t_tokugawa_sokoku **yakuza, char news)
{
	if (news == 'N')
	{
		(*yakuza)->map->dir = 'N';
		(*yakuza)->kumicho->direction.w = 0.0;
		(*yakuza)->kumicho->direction.h = -1.0;
	}
	else if (news == 'S')
	{
		(*yakuza)->map->dir = 'S';
		(*yakuza)->kumicho->direction.w = 0.0;
		(*yakuza)->kumicho->direction.h = 1.0;
	}
	else if (news == 'W')
	{
		(*yakuza)->map->dir = 'W';
		(*yakuza)->kumicho->direction.w = -1.0;
		(*yakuza)->kumicho->direction.h = 0.0;	
	}
	else if (news == 'E')
	{
		(*yakuza)->map->dir = 'E';
		(*yakuza)->kumicho->direction.w = 1.0;
		(*yakuza)->kumicho->direction.h = 0.0;
	}
}

void	set_plane(t_tokugawa_sokoku **yakuza, char news)
{
	if (news == 'N')
	{
		(*yakuza)->map->plane.w = 0.66;
		(*yakuza)->map->plane.h = 0;
		(*yakuza)->map->angle = 
	}
	else if (news == 'S')
	{
		(*yakuza)->map->dir = 'S';
		(*yakuza)->kumicho->direction.w = 0.0;
		(*yakuza)->kumicho->direction.h = 1.0;
	}
	else if (news == 'W')
	{
		(*yakuza)->map->dir = 'W';
		(*yakuza)->kumicho->direction.w = -1.0;
		(*yakuza)->kumicho->direction.h = 0.0;	
	}
	else if (news == 'E')
	{
		(*yakuza)->map->dir = 'E';
		(*yakuza)->kumicho->direction.w = 1.0;
		(*yakuza)->kumicho->direction.h = 0.0;
	}
}

void 	init_kumicho_2(t_tokugawa_sokoku **yakuza)
{
	int 	w;
	int 	h;

	h = 0;
	while ((*yakuza)->map[h])
	{
		w = 0;
		while ((*yakuza)->map[h][w])
		{
			if (is_direct((*yakuza)->map[h][w]))
			{
				(*yakuza)->kumicho->offset.w = w + 0.5;
				(*yakuza)->kumicho->offset.h = h + 0.5;
				set_dir(&(*yakuza), (*yakuza)->map[h][w]);
				set_plane(&(*yakuza), (*yakuza)->map[h][w]);
			}
			w++;
		}
		h++;
	}
}

// func - 4
void	init_kumicho(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->kumicho = malloc(sizeof(t_kumicho));
	if (!(*yakuza)->kumicho)
		malloc_err();
	init_kumicho_2(&(*yakuza));
	(*yakuza)->kumicho->plane.w =  0.0;
	(*yakuza)->kumicho->plane.h = 0.0;
	(*yakuza)->kumicho->angle = 0.0;
}

// func - 5
void 	init_tokugawa_sokoku(t_tokugawa_sokoku **yakuza)
{
	(*yakuza) = malloc(sizeof(t_tokugawa_sokoku));
	if (!(*yakuza))
		malloc_err();

	init_mlx(&(*yakuza)->mlx);
	init_mouse(&(*yakuza)->mouse, (*yakuza)->mlx);
	init_kumicho(&(*yakuza));
	(*yakuza)->img = mlx_new_image((*yakuza)->mlx, WIDTH , HEIGHT);
    if (!(*yakuza)->img || (mlx_image_to_window((*yakuza)->mlx, (*yakuza)->img, 0, 0) < 0))
		return ;
	init_minimap(&(*yakuza));
}