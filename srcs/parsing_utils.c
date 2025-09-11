/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:05:51 by modat             #+#    #+#             */
/*   Updated: 2025/09/11 14:30:38 by modat            ###   ########.fr       */
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
