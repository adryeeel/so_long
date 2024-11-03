/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:49:03 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/31 23:41:33 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static t_coord *ft_freeable_start(t_coord start)
{
	t_coord *start_copy;

	start_copy = ft_calloc(1, sizeof(t_coord));

	if (!start_copy)
		return (NULL);

	start_copy->x = start.x;
	start_copy->y = start.y;

	return (start_copy);
}

t_error ft_points_setup(t_coord start, t_queue *points)
{
	t_coord *start_copy;

	start_copy = ft_freeable_start(start);

	if (!start_copy)
		return (ERR_MAP_PATH_ALLOC);

	ft_queue_init(points);
	ft_enqueue(points, start_copy);

	return (OK);
}