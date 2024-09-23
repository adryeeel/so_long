/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:06:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 00:39:41 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_emap_setup(t_map *map, char *raw_map[])
{
	if (!map || !raw_map)
		return (false);

	map->matrix = ft_cmap_matrix(raw_map);

	if (!map->matrix)
		return (true);

	map->width = ft_strlen(raw_map[0]);
	map->height = ft_strarr_length(raw_map);

	return (true);
}