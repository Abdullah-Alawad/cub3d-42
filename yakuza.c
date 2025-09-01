/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yakuza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modat <modat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:08:28 by modat             #+#    #+#             */
/*   Updated: 2025/09/01 15:13:20 by modat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yakuza.h"

int	not_valid_file(char *file)
{
	int 	len;
	int		i;
	char	ext[4];

	len = ft_strlen(file);
	i = 0;
	while (i < 4 && len >= 0)
	{
		ext[i] = file[len - 1];
		len--;
		i++;
	}
	ft_putstr_fd(ext, 1);
	if (ft_strncmp(ext, "buc.", ft_strlen(ext)) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		strerror(-1);
		return (1);
	}
	if (not_valid_file(av[1]))
	{
		strerror(-1);
		return (1);
	}
	ft_putstr_fd("passed\n", 1);
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		strerror(-1);
		return (1);
	}

    // 1) parsing inputs
    // 2) map
            // 2.1
    // 3)
}