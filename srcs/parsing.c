/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 23:57:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	allocate_map(t_map **map)
{
	(*map) = malloc(sizeof(t_map));
	if (!*map)
		malloc_err();
	(*map)->wall = malloc(sizeof(t_wall_path));
	if (!(*map)->wall)
		malloc_err();
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->player_count = 0;
}

// func - 2
static void	init_map(t_map **map, char *map_buf)
{
	if (!map_buf)
	{
		printf("not there\n");
	}
	(*map)->map = ft_split(map_buf, '\n');
	if (!(*map)->map)
		malloc_err();
	copy_map(&(*map));
}

// func - 3
static void	set_path(char *buf, t_map **map)
{
	int	i;

	i = 0;
	if (buf[i] == 'N')
	{
		(*map)->wall->north = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->north))
		{
			free((*map)->wall->north);
			(*map)->wall->north = NULL;
			exit(1);
		}
	}
	else if (buf[i] == 'S')
	{
		(*map)->wall->south = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->south))
		{
			free((*map)->wall->south);
			(*map)->wall->south = NULL;
			exit(1);
		}
	}
	else if (buf[i] == 'W')
	{
		(*map)->wall->west = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->west))
		{
			free((*map)->wall->west);
			(*map)->wall->west = NULL;
			exit(1);
		}
	}
	else if (buf[i] == 'E')
	{
		(*map)->wall->east = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->east))
		{
			free((*map)->wall->east);
			(*map)->wall->east = NULL;
			exit(1);
		}
	}
}

// func - 4
static void	parse_init(char *buf, t_map **map, char **map_buf)
{
	if (!buf)
	{
		return ;
	}
	if (is_direction(buf) == 1)
	{
		set_path(buf, map);
	}
	else if (is_floor_cieling(buf) == 1)
	{
		set_color(buf, map);
	}
	else if (is_map(buf) == 1)
	{
		(*map)->height++;
		get_width_buf(buf, map, map_buf);
	}
}

// func - 5
int	parsing_reading(int ac, char **av, t_map **map)
{
	static char	*map_buf;
	int			fd;
	char		*buf;

	map_buf = NULL;
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	buf = get_next_line(fd);
	while (buf)
	{
		is_map_valid(buf);
		parse_init(buf, map, &map_buf);
		free(buf);
		buf = get_next_line(fd);
	}
	init_map(map, map_buf);
	save_player_positions(map);
	if (flood_fill((*map), (*map)->py, (*map)->px) == 0)
	{
		printf("map not closed\n");
		exit(1);
	}
	free(map_buf);
	close(fd);
	free(buf);
	return (0);
}
