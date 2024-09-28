/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:12:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 04:27:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_map_process(t_map *map, char *map_path)
{
	t_error err;
	char **grid;

	grid = NULL;

	err = ft_check_ext(map_path);
	if (err)
		return (err);

	err = ft_map_read(&grid, map_path);
	if (err)
		return (err);

	ft_map_setup(map, grid);

	err = ft_map_check(*map);
	if (err)
	{
		ft_map_free(grid);
		return (err);
	}

	return (OK);
}
