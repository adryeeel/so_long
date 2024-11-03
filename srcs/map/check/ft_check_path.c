/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:32 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/31 23:38:16 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_enqueue_points(t_map map, t_queue *points)
{
	int x;
	size_t y;
	t_coord *point;

	ft_queue_init(points);

	y = 0;
	while (++y < map.height)
	{
		x = 0;
		while (++x < (int)map.width)
		{
			point = ft_calloc(1, sizeof(t_coord));
			if (!point)
				return (ERR_MAP_PATH_ALLOC);

			point->x = x;
			point->y = y;

			if (map.grid[y][x] == START_POINT ||
				map.grid[y][x] == EXIT_POINT ||
				map.grid[y][x] == COLLECTIBLE)
			{
				ft_enqueue(points, point);
				continue;
			}
			free(point);
		}
	}
	return (OK);
}

t_error ft_check_path(t_map map)
{
	t_error err;
	t_coord start;
	t_coord *pos;
	t_queue points;

	start = ft_map_search(map, START_POINT, (t_coord){1, 1});

	err = ft_enqueue_points(map, &points);
	if (err)
		return (ft_points_free(points, NULL), err);

	while (points.length > 0)
	{
		pos = ft_dequeue(&points);
		err = ft_bfs_path(map, start, *pos);

		if (err && !ft_error_is(err, ERR_MAP_PATH))
			return (ft_points_free(points, pos), err);

		if (err && map.grid[pos->y][pos->x] == EXIT_POINT)
			return (ft_points_free(points, pos), ERR_MAP_PATH_EXIT);

		if (err && map.grid[pos->y][pos->x] == COLLECTIBLE)
			return (ft_points_free(points, pos), ERR_MAP_PATH_COLL);

		free(pos);
	}
	return (err);
}
