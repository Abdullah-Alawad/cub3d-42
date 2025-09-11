/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/08 15:48:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void    allocate_map(t_map **map)
{
    (*map) = malloc(sizeof(t_map));
    if (!*map)
        malloc_err();
    (*map)->wall = malloc(sizeof(t_wall_path));
    if (!(*map)->wall)                  // TODO: needs free
        malloc_err();
    (*map)->width = 0;
    (*map)->height = 0;
}

// func - 2
static void	init_map(t_map **map, char *map_buf)
{
    if (!map_buf)
    {
        printf("not there\n");
    }
    (*map)->map = ft_split(map_buf, '\n'); 
	if (!(*map)->map)
		malloc_err();
}

// func - 3
static void    set_path(char *buf, t_map **map)
{
    int i;

    i = 0;
    if (buf[i] == 'N')
    {
        i += 2;
        (*map)->wall->north = ft_strtrim(&buf[i], " /r/n/t");
    }
    else if (buf[i] == 'S')
    {
        i += 2;
        (*map)->wall->south = ft_strtrim(&buf[i], " /r/n/t");
    }
    else if (buf[i] == 'W')
    {
        i += 2;
        (*map)->wall->west = ft_strtrim(&buf[i], " /r/n/t");
    }
    else if (buf[i] == 'E')
    {
        i += 2;
        (*map)->wall->east = ft_strtrim(&buf[i], " /r/n/t");
    }
}

// func - 4
static void    parse_init(char *buf, t_map **map, char **map_buf)
{
    if (!buf)
    {
        return ;
    }
    if (is_direction(buf) == 1)
    {
        set_path(buf, map);
    }
    else if (is_floor_cieling(buf) == 1)
    {
        set_color(buf, map);
    }
    else if (is_map(buf))
    {
        (*map)->height++;
        get_width_buf(buf, map, map_buf);
    }
}

// func - 5
int     parsing_reading(int ac, char **av, t_map **map)
{
    if (ac != 2)
    {
        return (1);
    }
	static char *map_buf = NULL;
    int fd;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    char *buf;
    buf = get_next_line(fd);
    while (buf)
    {
        parse_init(buf, map, &map_buf);
        free(buf);
        buf = get_next_line(fd);
    }
    init_map(map, map_buf);
    free(map_buf);
    close(fd);
    free(buf);
    return (0);
}
