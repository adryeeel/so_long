/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visited_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:35:05 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/31 23:42:25 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_visited_setup(t_map map, t_coord start, int ***visited)
{
	*visited = ft_matrix_alloc(map.width, map.height);

	if (!*visited)
		return (ERR_MAP_PATH_ALLOC);

	(*visited)[start.y][start.x] = true;

	return (OK);
}