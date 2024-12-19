/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avatar_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:13:26 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/08 12:13:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_avatar_setup(t_avatar *av, t_map map)
{
	t_coord pos;

	pos = ft_map_search(map, START_POINT, (t_coord){0, 0});

	av->x = pos.x;
	av->y = pos.y;
	av->died = false;
	av->orient = RIGHT;

	if (map.grid[av->y][av->x + 1] == WALL)
		av->orient = LEFT;
}
