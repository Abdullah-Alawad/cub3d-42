/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/24 15:30:41 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	init_map(t_map **map, char *map_buf)
{
	(*map)->map = ft_split(map_buf, '\n');
	if (!(*map)->map)
		malloc_err();
	copy_map(&(*map));
}

// func - 2
static int	ifs_path(t_map **map, int i, char *buf)
{
	if (buf[i] == 'N')
	{
		(*map)->wall->north = ft_strtrim(&buf[i + 2], " \r\n\t");
		if (!is_path_valid((*map)->wall->north))
			return (0);
	}
	else if (buf[i] == 'S')
	{
		(*map)->wall->south = ft_strtrim(&buf[i + 2], " \r\n\t");
		if (!is_path_valid((*map)->wall->south))
			return (0);
	}
	else if (buf[i] == 'W')
	{
		(*map)->wall->west = ft_strtrim(&buf[i + 2], " \r\n\t");
		if (!is_path_valid((*map)->wall->west))
			return (0);
	}
	else if (buf[i] == 'E')
	{
		(*map)->wall->east = ft_strtrim(&buf[i + 2], " \r\n\t");
		if (!is_path_valid((*map)->wall->east))
			return (0);
	}
	return (1);
}

// func - 3
int	set_path(char *buf, t_map **map)
{
	int	i;

	i = 0;
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	if (ifs_path(map, i, buf) == 0)
		return (0);
	return (1);
}

// func - 4
void	set_flags_values(t_parsing_flags *flags)
{
	flags->found_map = 0;
	flags->found_no = 0;
	flags->found_so = 0;
	flags->found_we = 0;
	flags->found_ea = 0;
	flags->found_f = 0;
	flags->found_c = 0;
	flags->error = 0;
	flags->i = 0;
}

// func - 5
int	parsing_reading(int ac, char **av, t_map **map)
{
	static char		*map_buf = NULL;
	int				fd;
	t_parsing_flags	flags;

	set_flags_values(&flags);
	if (open_map(&fd, av, ac) == 1)
		return (0);
	read_map(&flags, map, &map_buf, fd);
	if (check_error(&flags, map, map_buf, fd) == 0)
		return (0);
	if (flood_fill((*map), (*map)->py, (*map)->px) == 0)
	{
		close(fd);
		if (map_buf)
			free(map_buf);
		write(2, "map not closed\n", 15);
		return (0);
	}
	close(fd);
	if (map_buf)
		free(map_buf);
	return (1);
}
