/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_surronded.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:14:20 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:46:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define WALL '1'

static bool ft_check_top(char *top_row)
{
	size_t x;

	x = 0;
	while (top_row[x])
	{
		if (top_row[x] != WALL)
			return (false);
		x++;
	}

	return (true);
}

static bool ft_check_bottom(char *bottom_row)
{
	size_t x;

	x = 0;
	while (bottom_row[x])
	{
		if (bottom_row[x] != WALL)
			return (false);
		x++;
	}
	return (true);
}

bool ft_check_surrounded(t_map map)
{
	size_t y;

	if (!ft_check_top(map.grid[0]))
		return (false);

	if (!ft_check_bottom(map.grid[map.height - 1]))
		return (false);

	y = 1;
	while (y < map.height - 1)
	{
		if (map.grid[y][0] != WALL)
			return (false);

		if (map.grid[y][map.width - 1] != WALL)
			return (false);

		y++;
	}
	return (true);
}
