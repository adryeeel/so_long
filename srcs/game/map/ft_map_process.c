/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:12:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 17:37:33 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_map_process(t_map *map, char *map_path)
{
	t_error err;
	char **raw_map;

	raw_map = ft_cmap_read(map_path);

	if (!raw_map)
		return (ERR_MAP_READ);

	err = ft_cmap_isrect(raw_map);
	if (err)
	{
		ft_cmap_free(raw_map);
		return (err);
	}

	err = ft_emap_setup(map, raw_map);
	if (err)
	{
		ft_cmap_free(raw_map);
		return (err);
	}

	ft_cmap_free(raw_map);

	err = ft_emap_check(map);
	if (err)
	{
		ft_matrix_free(map->matrix);
		return (err);
	}

	return (OK);
}
