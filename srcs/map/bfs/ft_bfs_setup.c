/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:13:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/02 05:05:50 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_bfs_setup(t_map map, t_coord start, t_queue *points, int ***visited)
{
	t_error err;

	err = ft_points_setup(start, points);

	if (err)
		return (err);

	err = ft_visited_setup(map, start, visited);

	if (err)
	{
		ft_points_free(*points, NULL);
		return (err);
	}

	return (OK);
}