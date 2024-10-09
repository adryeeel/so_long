/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:43:34 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 22:49:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_flags ft_flags_setup(void)
{
	t_flags flags;

	flags.exit = 0;
	flags.start = 0;
	flags.patrol = 0;
	flags.unknown = 0;
	flags.collectible = 0;

	return (flags);
}

t_flags ft_flags_parse(t_map map)
{
	size_t x;
	size_t y;
	t_flags flags;

	flags = ft_flags_setup();

	y = 0;
	while (++y < map.height)
	{
		x = 0;
		while (++x < map.width)
		{
			if (map.grid[y][x] == EXIT_POINT)
				flags.exit++;

			if (map.grid[y][x] == START_POINT)
				flags.start++;

			if (map.grid[y][x] == COLLECTIBLE)
				flags.collectible++;

			if (!ft_map_iscomp(map.grid[y][x]))
				flags.unknown++;
		}
	}

	return (flags);
}

t_error ft_check_comp(t_map map)
{
	t_flags flags;

	flags = ft_flags_parse(map);

	if (flags.exit != 1)
		return (ERR_MAP_EXIT);

	if (flags.start != 1)
		return (ERR_MAP_START);

	if (flags.unknown)
		return (ERR_MAP_UNKNOWN);

	if (!flags.collectible)
		return (ERR_MAP_COLLECTIBLE);

	return (OK);
}
