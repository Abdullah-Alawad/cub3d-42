/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:34:31 by modat             #+#    #+#             */
/*   Updated: 2025/09/09 16:55:55 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

void print_map(t_map *m)
{
    if (!m) {
        printf("t_map pointer is NULL\n");
        return;
    }

    printf("Map size: %d x %d\n", m->height, m->width);

    if (m->map) {
        printf("\nMap layout:\n");
        for (int i = 0; i < m->height; i++) {
            if (m->map[i])
                printf("%s\n", m->map[i]);
        }
    }

    if (m->floor)
        printf("\nFloor color: R:%d G:%d B:%d\n",
               m->floor->r, m->floor->g, m->floor->b);

    if (m->ceiling)
        printf("Ceiling color: R:%d G:%d B:%d\n",
               m->ceiling->r, m->ceiling->g, m->ceiling->b);

    if (m->wall) {
        printf("\nWall textures:\n");
        if (m->wall->north) printf("  North: %s\n", m->wall->north);
        if (m->wall->south) printf("  South: %s\n", m->wall->south);
        if (m->wall->west)  printf("  West:  %s\n", m->wall->west);
        if (m->wall->east)  printf("  East:  %s\n", m->wall->east);
    }
}

