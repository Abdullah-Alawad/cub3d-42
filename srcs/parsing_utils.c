/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:05:51 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 08:32:50 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
int	is_direction(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
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
int	is_floor_cieling(char *buf, int i)
{
	if (buf[i] == 'F')
		return (1);
	else if (buf[i] == 'C')
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
		if (buf[i] != '1' && buf[i] != '0' && buf[i] != 'N'
			&& buf[i] != 'S' && buf[i] != 'W' && buf[i] != 'E'
			&& buf[i] != ' ' && buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// func - 4
// static void	check_allowed_space(char *line, int i)
// {
// 	if (i > 0)
// 	{
// 		if (line[i - 1] == '0')
// 		{
// 			ft_putstr_fd("Error:\nspace in mid of map\n", 2);
// 			exit(1);
// 		}
// 	}
// 	i++;
// 	while (line[i] == ' ')
// 		i++;
// 	if (line[i] != '1' && line[i] != '\n')
// 	{
// 		ft_putstr_fd("Error:\nspace in wrong place\n", 2);
// 		exit(1);
// 	}
// }

// func - 5
void	check_line(t_map **map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			(*map)->player_count++;
			(*map)->player_direction = line[i];
		}
		i++;
	}
}
