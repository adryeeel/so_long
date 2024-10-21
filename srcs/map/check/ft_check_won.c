/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_won.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:13:17 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 18:57:35 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_check_won(t_map map)
{
	size_t x;
	size_t y;

	y = 0;
	while (++y < map.height)
	{
		x = 0;
		while (++x < map.width)
		{
			if (map.grid[y][x] == COLLECTIBLE)
				return (false);
		}
	}
	return (true);
}