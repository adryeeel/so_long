/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:13:12 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/01 04:35:50 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define TOTAL_DIRECTIONS 4

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
			return (ft_matrix_free(directions), ERR_MAP_PATH_ALLOC);

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