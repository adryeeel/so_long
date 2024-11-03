/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:03:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/02 04:57:09 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_bfs_path(t_map map, t_coord start, t_coord end)
{
	t_error err;
	int **visited;
	t_queue points;

	visited = NULL;

	err = ft_bfs_setup(map, start, &points, &visited);
	if (err)
		return (err);

	err = ft_bfs_process(map, end, &points, visited);
	ft_bfs_cleanup(points, visited);

	return (err);
}
