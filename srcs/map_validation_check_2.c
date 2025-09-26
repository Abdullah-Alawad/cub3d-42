/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_check_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:37:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 07:38:42 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

// func - 1
void	set_default_values(t_tokugawa_sokoku **yakuza)
{
	(*yakuza)->minimap = NULL;
	(*yakuza)->map = NULL;
	(*yakuza)->camera = NULL;
	(*yakuza)->kumicho = NULL;
	(*yakuza)->texture = NULL;
}
