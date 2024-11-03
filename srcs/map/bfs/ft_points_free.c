/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:43:18 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/01 00:42:43 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_points_free(t_queue points, t_coord *pos)
{
	t_coord *point;

	if (pos)
		free(pos);

	while (points.length > 0)
	{
		point = ft_dequeue(&points);
		free(point);
	}
}
