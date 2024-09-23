/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:06:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 17:57:36 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_error ft_emap_setup(t_map *map, char *raw_map[])
{
	if (!raw_map)
		return (ERR_MAP_READ);

	map->matrix = ft_cmap_matrix(raw_map);

	if (!map->matrix)
		return (ERR_MAP_MATRIX);

	map->width = ft_strlen(raw_map[0]);
	map->height = ft_strarr_length(raw_map);

	return (OK);
}
