/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_bfs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:03:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/27 23:05:20 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_bfs_setup(t_map map, t_coord start, int ***visited, t_coord **sp)
{
	*visited = ft_matrix_alloc(map.width, map.height);

	if (!*visited)
		return (ERR_MAP_PATH_ALLOC);

	(*visited)[start.y][start.x] = true;

	*sp = ft_calloc(1, sizeof(t_coord));

	if (!*sp)
	{
		ft_matrix_free(*visited);
		return (ERR_MAP_PATH_ALLOC);
	}

	(*sp)->x = start.x;
	(*sp)->y = start.y;

	return (OK);
}

bool ft_bfs_isvalid(t_map map, t_coord pos, int **visited)
{
	size_t ok;

	ok = 0;
	if (pos.x >= 0 && pos.x < (int)map.width)
		ok++;

	if (pos.y >= 0 && pos.y < (int)map.height)
		ok++;

	if (!visited[pos.y][pos.x])
		ok++;

	if (map.matrix[pos.y][pos.x] != WALL)
		ok++;

	return (ok == 4);
}

t_error ft_bfs_edges(t_map map, t_queue *q, t_coord curr, int **visited)
{
	int i;
	t_coord *pos;
	int **directions;

	i = -1;
	directions = ft_dirs_setup();
	while (++i < TOTAL_DIRECTIONS)
	{
		pos = ft_calloc(1, sizeof(t_coord));

		if (!pos)
		{
			ft_points_free(*q);
			return (ERR_MAP_PATH_ALLOC);
		}

		pos->x = curr.x + directions[i][0];
		pos->y = curr.y + directions[i][1];

		if (ft_bfs_isvalid(map, *pos, visited))
		{
			ft_enqueue(q, pos);
			visited[pos->y][pos->x] = true;
			continue;
		}
		free(pos);
	}
	ft_matrix_free(directions);
	return (OK);
}

t_error ft_emap_bfs(t_map map, t_coord start, t_coord end)
{
	t_queue q;
	t_error err;
	t_coord *pos;
	t_coord *s_pos;
	int **visited;

	s_pos = NULL;
	visited = NULL;
	err = ft_bfs_setup(map, start, &visited, &s_pos);

	if (err)
		return (err);

	ft_queue_init(&q);
	ft_enqueue(&q, s_pos);

	while (q.length > 0)
	{
		pos = ft_dequeue(&q);

		if (pos->x == end.x && pos->y == end.y)
		{
			free(pos);
			err = OK;
			break;
		}
		err = ft_bfs_edges(map, &q, *pos, visited);
		free(pos);
		if (err)
			break;
		err = ERR_MAP_PATH;
	}
	ft_points_free(q);
	ft_matrix_free(visited);
	return (err);
}
