/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:49:41 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/02 05:05:53 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_bfs_process(t_map map, t_coord end, t_queue *points, int **visited)
{
	t_error err;
	t_coord *pos;

	ft_bfs_goal(SET, map.grid[end.y][end.x]);

	while (points->length > 0)
	{
		pos = ft_dequeue(points);

		if (ft_bfs_isgoal(*pos, end))
			return (free(pos), OK);

		err = ft_bfs_edges(map, points, *pos, visited);
		if (err)
		{
			free(pos);
			break;
		}

		err = ERR_MAP_PATH;
		free(pos);
	}

	return (err);
}