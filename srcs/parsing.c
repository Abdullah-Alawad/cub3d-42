/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/24 14:59:26 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static void	init_map(t_map **map, char *map_buf)
{
	(*map)->map = ft_split(map_buf, '\n');
	if (!(*map)->map)
		malloc_err();
	copy_map(&(*map));
}

// func - 2
static void	ifs_path(t_map **map, int i, char *buf)
{
	if (buf[i] == 'N')
	{
		(*map)->wall->north = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->north))
			invalid_path((*map)->wall->north);
	}
	else if (buf[i] == 'S')
	{
		(*map)->wall->south = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->south))
			invalid_path((*map)->wall->south);
	}
	else if (buf[i] == 'W')
	{
		(*map)->wall->west = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->west))
			invalid_path((*map)->wall->west);
	}
	else if (buf[i] == 'E')
	{
		(*map)->wall->east = ft_strtrim(&buf[i + 2], " /r/n/t");
		if (!is_path_valid((*map)->wall->east))
			invalid_path((*map)->wall->east);
	}
}

// func - 3
static void	set_path(char *buf, t_map **map)
{
	int	i;

	i = 0;
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	ifs_path(map, i, buf);
}

// func - 4
static int	parse_init(char *buf, t_map **map, char **map_buf)
{
	if (!buf)
		return (0);
	if (is_direction(buf) == 1)
		set_path(buf, map);
	else if (is_floor_cieling(buf) == 1)
	{
		if (set_color(buf, map) == 0)
			return (0);
	}
	else if (is_map(buf) == 1)
	{
		(*map)->height++;
		get_width_buf(buf, map, map_buf);
	}
	return (1);
}

// func - 5
int	parsing_reading(int ac, char **av, t_map **map)
{
	static char	*map_buf = NULL;
	int			fd;
	char		*buf;

	if (open_map(&fd, av, ac) == 1)
		return (1);
	buf = get_next_line(fd);
	while (buf)
	{
		is_map_valid(buf);
		if (parse_init(buf, map, &map_buf) == 0)
			return (close(fd), free(buf), free(map_buf), 0);
		free(buf);
		buf = get_next_line(fd);
	}
	init_map(map, map_buf);
	save_player_positions(map);
	if (flood_fill((*map), (*map)->py, (*map)->px) == 0)
	{
		write(2, "map not closed\n", 15);
		return (0);
	}
	close(fd);
	frees(buf, map_buf);
	return (1);
}
