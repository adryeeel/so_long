/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:12:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 22:27:28 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static t_error ft_cmap_process(char **raw_map[], char *map_path)
{
	t_error err;

	err = ft_check_ext(map_path);
	if (err)
		return (err);

	err = ft_cmap_read(raw_map, map_path);
	if (err)
		return (err);

	err = ft_cmap_check(*raw_map);
	if (err)
	{
		ft_cmap_free(*raw_map);
		return (err);
	}
	return (OK);
}

static t_error ft_emap_process(t_map *map, char *raw_map[])
{
	t_error err;

	err = ft_emap_setup(map, raw_map);
	if (err)
		return (err);

	err = ft_emap_check(map);
	if (err)
	{
		ft_matrix_free(map->matrix);
		return (err);
	}

	return (OK);
}

t_error ft_map_process(t_map *map, char *map_path)
{
	t_error err;
	char **raw_map;

	raw_map = NULL;
	err = ft_cmap_process(&raw_map, map_path);
	if (err)
		return (err);

	err = ft_emap_process(map, raw_map);
	ft_cmap_free(raw_map);

	if (err)
		return (err);
	return (OK);
}
