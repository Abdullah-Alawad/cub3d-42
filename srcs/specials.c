/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specials.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:51:56 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:29:22 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
int	special_err1(t_parsing_flags *flags, char *buf)
{
	flags->error = 1;
	frees(buf);
	return (0);
}

// func - 2
int	special_err2(char *str)
{
	free(str);
	return (0);
}

// func - 3
int	check_error(t_parsing_flags *flags, t_map **map, char *map_buf, int fd)
{
	if (flags->error || !(flags->found_no && flags->found_so
			&& flags->found_we && flags->found_ea && flags->found_f
			&& flags->found_c && flags->found_map))
	{
		close(fd);
		if (map_buf)
		{
			free(map_buf);
			map_buf = NULL;
		}
		ft_putstr_fd("Error:\nInvalid map format\n", 2);
		return (0);
	}
	if (init_map(map, map_buf) == 0)
		return (init_error(fd, map_buf));
	if (save_player_positions(map) == 0)
	{
		close(fd);
		if (map_buf)
			free(map_buf);
		ft_putstr_fd("Error:\nNo Player in map\n", 2);
		return (0);
	}
	return (1);
}

// func - 4
int	check_color_line(char *buf, int i)
{
	int	is_two;

	i++;
	is_two = 0;
	while (buf[i])
	{
		if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '+'
			&& !ft_isdigit(buf[i]) && buf[i] != ',' && buf[i] != '\n')
			return (0);
		if (buf[i] == ',')
			is_two++;
		i++;
	}
	if (is_two == 2)
		return (1);
	else
		return (0);
}

void	free_map_exit(t_map *map)
{
	free_map(map);
	exit (1);
}
