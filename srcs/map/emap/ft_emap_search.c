/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:32:13 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/27 18:34:10 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_coord ft_emap_search(t_map map, t_mapc comp)
{
	size_t x;
	size_t y;
	t_coord pos;

	y = 0;
	pos.x = 0;
	pos.y = 0;

	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.matrix[y][x] == (int)comp)
				return (pos);
			pos.x = ++x;
		}
		pos.y = ++y;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
