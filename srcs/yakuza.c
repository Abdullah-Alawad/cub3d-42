/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/23 23:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

int	main(int ac, char **av)
{
	t_tokugawa_sokoku	*yakuza;

	setup_config(&yakuza, av, ac);
	mlx_close_hook(yakuza->mlx, close_win, yakuza);
	mlx_key_hook(yakuza->mlx, keypress_hook, yakuza);
	mlx_loop_hook(yakuza->mlx, enter_tokugawa_sokoku, yakuza);
	mlx_loop(yakuza->mlx);
	mlx_terminate(yakuza->mlx);
	free_struct(yakuza);
	return (0);
}
