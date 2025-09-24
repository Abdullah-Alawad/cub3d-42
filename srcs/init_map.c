/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:02:08 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 14:57:40 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	init_map_buf(char **map_buf)
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
static int	add_color(t_rgb *draw, char *buf)
{
	char	*b;
	char	**comb;
	int		k;

	k = 0;
	b = ft_strtrim(buf, " /r/t/nFC");
	comb = ft_split(b, ',');
	if (!*comb || !comb)
		malloc_err();
	while (comb[k])
		k++;
	if (is_colors_checker(comb, &draw) == 0 || k != 3)
	{
		free_double_array(comb);
		free(b);
		write(2, "Error: invalid colors set\n", 26);
		return (0);
	}
	free(b);
	free_double_array(comb);
	return (1);
}

// func - 4
int	set_color(char *buf, t_map **map)
{
	if (buf[0] == 'F')
	{
		(*map)->floor = malloc(sizeof(t_rgb));
		if (!(*map)->floor)
			return (0);
		if (add_color((*map)->floor, buf) == 0)
			return (0);
	}
	else if (buf[0] == 'C')
	{
		(*map)->ceiling = malloc(sizeof(t_rgb));
		if (!(*map)->ceiling)
			return (0);
		if (add_color((*map)->ceiling, buf) == 0)
			return (0);
	}
	return (1);
}

// func - 5
int	setting_map(t_map **map, char **av, int ac)
{
	allocate_map(map);
	if (parsing_reading(ac, av, map) == 0)
	{
		free_map((*map));
		return (1);
	}
	if ((*map)->player_count != 1)
	{
		free_map((*map));
		write(2, "players numbers is incorrect\n", 29);
		return (1);
	}
	return (0);
}
