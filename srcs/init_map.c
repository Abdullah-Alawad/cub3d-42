/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:02:08 by modat             #+#    #+#             */
/*   Updated: 2025/09/22 15:16:32 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void    init_map_buf(char **map_buf)
{
    if (!(*map_buf))
    {
        (*map_buf) = ft_strdup("");
        if (!(*map_buf))
            malloc_err();
    }
}

// func - 2
void	get_width_buf(char *buf, t_map **map, char **map_buf)
{
	char	*b;
	int		len;
	char	*tmp;

	b = ft_strtrim(buf, "\n");
	if (!b)
		malloc_err();
	init_map_buf(map_buf);
	tmp = b;
	b = ft_strjoin(b, "\n");
	if (!b)
		malloc_err();
	free(tmp);
	tmp = ft_strjoin((*map_buf), b);
	if (!tmp)
		malloc_err();
	free(*map_buf);
	(*map_buf) = tmp;
	len = ft_strlen(b) - 1;
	if ((*map)->width < len)
		(*map)->width = len;
	check_line(map, b);
	free(b);
}

// func - 3
static void	add_color(t_rgb *draw, char *buf)
{
	char	*b;
	char	**comb;

	b = ft_strtrim(buf, " /r/t/nFC");
	comb = ft_split(b, ',');
	if (!*comb || !comb)
		malloc_err();
	is_colors_checker(comb, &draw);
	free(b);
	free_arr(comb);
}

// func - 4
void	set_color(char *buf, t_map **map)
{
	if (buf[0] == 'F')
	{
		(*map)->floor = malloc(sizeof(t_rgb));
		if (!(*map)->floor)
			return ;
		add_color((*map)->floor, buf);
	}
	else if (buf[0] == 'C')
	{
		(*map)->ceiling = malloc(sizeof(t_rgb));
		if (!(*map)->ceiling)
			return ;
		add_color((*map)->ceiling, buf);
	}
}

void	print_cpy(char **map, int height)
{
	int width;
	
	// printf("Map (%d):\n", height);
    for (int y = 0; y < height; y++)
    {
		width = ft_strlen(map[y]);
        for (int x = 0; x < width; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

// func - 5
void 	setting_map(t_map **map, char **av, int ac)
{
	allocate_map(map);
	if (parsing_reading(ac, av, map) == 1)
	{
		// error & free
		exit_free();
	}
	if ((*map)->player_count != 1)
    {
        printf("players numbers is incorrect\n");
        exit_free();
    }

}
