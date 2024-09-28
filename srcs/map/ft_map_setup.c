/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:06:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 04:23:30 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_map_setup(t_map *map, char *grid[])
{
	map->grid = grid;
	map->width = ft_strlen(grid[0]);
	map->height = ft_strarr_length(grid);
}
