/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:12:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 00:45:49 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_map_process(t_map *map, char *map_path)
{
	char **raw_map;

	raw_map = ft_cmap_read(map_path);

	if (!map || !raw_map)
		return (false);

	if (!ft_cmap_isrect(raw_map))
	{
		ft_cmap_free(raw_map);
		return (false);
	}

	if (!ft_emap_setup(map, raw_map))
	{
		ft_cmap_free(raw_map);
		return (false);
	}

	ft_cmap_free(raw_map);

	if (!ft_emap_check(map))
	{
		ft_matrix_free(map->matrix);
		return (false);
	}

	return (true);
}
