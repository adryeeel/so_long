/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:32 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 22:58:16 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_enqueue_points(t_map map, t_queue *points)
{
	int x;
	size_t y;
	t_coord *point;

	ft_queue_init(points);

	y = 0;
	while (y < map.height)
	{
		x = -1;
		while (++x < (int)map.width)
		{
			point = ft_calloc(1, sizeof(t_coord));

			if (!point)
			{
				ft_points_free(*points);
				return;
			}

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
		y++;
	}
}

t_error ft_check_path(t_map map)
{
	t_error err;
	t_coord start;
	t_coord *pos;
	t_queue points;

	ft_enqueue_points(map, &points);
	start = ft_map_search(map, START_POINT, (t_coord){0, 0});

	while (points.length > 0)
	{
		pos = ft_dequeue(&points);
		err = ft_map_bfs(map, start, *pos);

		if (err && err != ERR_MAP_PATH)
			return (err);

		if (err && map.grid[pos->y][pos->x] == EXIT_POINT)
		{
			err = ERR_MAP_PATH_EXIT;
			break;
		}

		if (err && map.grid[pos->y][pos->x] == COLLECTIBLE)
		{
			err = ERR_MAP_PATH_COLL;
			break;
		}
		free(pos);
	}
	if (err)
	{
		free(pos);
		ft_points_free(points);
	}
	return (err);
}
