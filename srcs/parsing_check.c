/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:51:56 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:29:22 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	check_repetitivness(t_parsing_flags *flags, char dir)
{
	if (dir == 'N')
	{
		if (flags->found_no++)
			flags->error = 1;
	}
	else if (dir == 'S')
	{
		if (flags->found_so++)
			flags->error = 1;
	}
	else if (dir == 'W')
	{
		if (flags->found_we++)
			flags->error = 1;
	}
	else if (dir == 'E')
	{
		if (flags->found_ea++)
			flags->error = 1;
	}
}

// func - 2
int	add_direction(t_parsing_flags *flags, int i, char *buf, t_map **map)
{
	if (buf[i] == 'N' && buf[i + 1] == 'O')
		check_repetitivness(flags, 'N');
	else if (buf[i] == 'S' && buf[i + 1] == 'O')
		check_repetitivness(flags, 'S');
	else if (buf[i] == 'W' && buf[i + 1] == 'E')
		check_repetitivness(flags, 'W');
	else if (buf[i] == 'E' && buf[i + 1] == 'A')
		check_repetitivness(flags, 'E');
	if (flags->error == 1)
		return (0);
	if (set_path(buf, map) == 0)
	{
		flags->error = 1;
		return (0);
	}
	return (1);
}

// func - 3
int	add_color_line(t_parsing_flags *flags, int i, char *buf, t_map **map)
{
	if (buf[i] == 'F' && (buf[i + 1] == ' ' || buf[i +1] == '\t'))
	{
		if (flags->found_f++)
			flags->error = 1;
	}
	else if (buf[i] == 'C' && (buf[i + 1] == ' ' || buf[i +1] == '\t'))
	{
		if (flags->found_c++)
			flags->error = 1;
	}
	if (flags->error == 1)
		return (0);
	if (set_color(buf, map, i) == 0)
	{
		flags->error = 1;
		return (0);
	}
	return (1);
}

// func - 4
int	add_line(t_parsing_flags *flags, char *buf, char **map_buf, t_map **map)
{
	if (flags->found_map && (buf[flags->i] == '\n' || buf[flags->i] == '\0'))
		return (special_err1(flags, buf));
	if (!flags->found_map && is_direction(buf))
	{
		if (add_direction(flags, flags->i, buf, map) == 0)
			return (special_err1(flags, buf));
	}
	else if (!flags->found_map && is_floor_cieling(buf, flags->i))
	{
		if (add_color_line(flags, flags->i, buf, map) == 0)
			return (special_err1(flags, buf));
	}
	else if (is_map(buf))
	{
		flags->found_map = 1;
		(*map)->height++;
		if (get_width_buf(buf, map, map_buf) == 0)
			return (special_err1(flags, buf));
	}
	else
		flags->error = 1;
	frees(buf);
	if (flags->error)
		return (0);
	return (1);
}

// func - 5
void	read_map(t_parsing_flags *flags, t_map **map, char **map_buf, int fd)
{
	char	*buf;

	buf = get_next_line(fd);
	while (buf)
	{
		flags->i = 0;
		while (buf[flags->i] == ' ' || buf[flags->i] == '\t')
			flags->i += 1;
		if (buf[flags->i] == '\n' || buf[flags->i] == '\0')
		{
			free(buf);
			buf = NULL;
			buf = get_next_line(fd);
			continue ;
		}
		if (add_line(flags, buf, map_buf, map) == 0)
			break ;
		buf = get_next_line(fd);
	}
	get_next_line(-1);
}
