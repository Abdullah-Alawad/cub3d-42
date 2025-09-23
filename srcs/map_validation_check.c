/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:59:57 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 00:01:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
static int	is_newline(char *buf)
{
	if (buf[0] == '\n')
		return (1);
	return (0);
}

// func - 2
int	is_path_valid(char *buf)
{
	int	fd;
	int	len;

	len = strlen(buf);
	buf[len - 1] = 0;
	fd = open(buf, O_RDONLY);
	if (fd == -1)
	{
		perror("invalid texture path");
		return (0);
	}
	close(fd);
	return (1);
}

// func - 3
int	is_colors_valid(int nbr)
{
	if (nbr >= 0 && nbr <= 255)
		return (1);
	else
	{
		perror("invalid color range");
		return (0);
	}
}

// func - 4
int	is_colors_checker(char **comb, t_rgb **draw)
{
	int	k;

	k = 0;
	if (comb[k])
	{
		(*draw)->r = ft_atoi(comb[k]);
		if (!is_colors_valid((*draw)->r))
			return (0);
		k++;
	}
	if (comb[k])
	{
		(*draw)->g = ft_atoi(comb[k]);
		if (!is_colors_valid((*draw)->g))
			return (0);
		k++;
	}
	if (comb[k])
	{
		(*draw)->b = ft_atoi(comb[k]);
		if (!is_colors_valid((*draw)->b))
			return (0);
		k++;
	}
	return (1);
}

// func - 5
int	is_map_valid(char *buf)
{
	if (is_direction(buf) == 1)
		return (1);
	if (is_floor_cieling(buf) == 1)
		return (1);
	else if (is_map(buf) == 1)
		return (1);
	else if (is_newline(buf) == 1)
		return (1);
	else
	{
		perror("unreognized input");
		// IMPORTANT
		// exit_free();
	}
	return (0);
}
