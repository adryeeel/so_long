/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_surronded.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:14:20 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 02:00:25 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static bool ft_check_top(t_map map)
{
	int *row;
	size_t x;

	x = 0;
	row = map.matrix[0];

	while (row[x] != -1)
	{
		if (row[x] != WALL)
			return (false);
		x++;
	}

	return (true);
}

static bool ft_check_bottom(t_map map)
{
	int *row;
	size_t x;

	x = 0;
	row = map.matrix[map.height - 1];

	while (row[x] != -1)
	{
		if (row[x] != WALL)
			return (false);
		x++;
	}
	return (true);
}

bool ft_check_surronded(t_map map)
{
	size_t y;

	if (!ft_check_top(map))
		return (false);

	if (!ft_check_bottom(map))
		return (false);

	y = 1;
	while (y < map.height - 1)
	{
		if (map.matrix[y][0] != WALL)
			return (false);

		if (map.matrix[y][map.width - 1] != WALL)
			return (false);

		y++;
	}
	return (true);
}
