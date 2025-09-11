/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:02:08 by modat             #+#    #+#             */
/*   Updated: 2025/09/11 15:33:58 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"


// func - 2
void	get_width_buf(char *buf, t_map **map, char **map_buf)
{
	char	*b;
	int		len;
	char	*tmp;

	b = ft_strtrim(buf, "\n");
	if (!b)
		malloc_err();
	if (!(*map_buf))
	{
		(*map_buf) = ft_strdup("");
		if (!(*map_buf))
			malloc_err();
	}
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
	free(b);
}

// func - 3
static void	add_color(t_rgb *draw, char *buf)
{
	char	*b;
	char	**comb;

	b = ft_strtrim(buf, " /r/t/nFC");
	comb = ft_split(b, ',');
	if (!*comb || !comb)
		malloc_err();
	is_colors_checker(comb, &draw);
	free(b);
	free_arr(comb);
}

// func - 4
void	set_color(char *buf, t_map **map)
{
	if (buf[0] == 'F')
	{
		(*map)->floor = malloc(sizeof(t_rgb));
		if (!(*map)->floor)
			return ;
		add_color((*map)->floor, buf);
	}
	else if (buf[0] == 'C')
	{
		(*map)->ceiling = malloc(sizeof(t_rgb));
		if (!(*map)->ceiling)
			return ;
		add_color((*map)->ceiling, buf);
	}
}
