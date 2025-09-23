/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:05:51 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 22:14:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
int	is_direction(char *buf)
{
	int	i;

	i = 0;
	if (buf[i] == 'N' && buf[i + 1] == 'O')
		return (1);
	else if (buf[i] == 'S' && buf[i + 1] == 'O')
		return (1);
	else if (buf[i] == 'W' && buf[i + 1] == 'E')
		return (1);
	else if (buf[i] == 'E' && buf[i + 1] == 'A')
		return (1);
	return (0);
}

// func - 2
int	is_floor_cieling(char *buf)
{
	if (buf[0] == 'F')
		return (1);
	else if (buf[0] == 'C')
		return (1);
	return (0);
}

// func - 3
int	is_map(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

// func - 4
static void	check_allowed_space(char *line, int i)
{
	if (i > 0)
	{
		if (line[i - 1] == '0')
		{
			perror("space in mid of map");
			exit(1);
		}
	}
	i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1' && line[i] != '\n')
	{
		perror("space in wrong place");
		exit(1);
	}
}

// func - 5
void	check_line(t_map **map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != '\n' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != ' ')
			exit(1);
		if (line[i] == ' ')
			check_allowed_space(line, i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			(*map)->player_count++;
			(*map)->player_direction = line[i];
		}
		i++;
	}
}
