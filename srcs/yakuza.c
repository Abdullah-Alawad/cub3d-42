/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:29:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/24 15:42:02 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

int	main(int ac, char **av)
{
	t_tokugawa_sokoku	*yakuza;

	if (ac != 2)
	{
		ft_putstr_fd("Error:\nAdd a map file or aguments too many\n", 2);
		exit (1);
	}
	setup_config(&yakuza, av, ac);
	mlx_close_hook(yakuza->mlx, close_win, yakuza);
	mlx_key_hook(yakuza->mlx, keypress_hook, yakuza);
	mlx_loop_hook(yakuza->mlx, enter_tokugawa_sokoku, yakuza);
	mlx_loop(yakuza->mlx);
	free_struct(yakuza);
	mlx_terminate(yakuza->mlx);
	free(yakuza);
	return (0);
}
