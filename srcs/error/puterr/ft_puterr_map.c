/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 01:04:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void ft_puterr_map_setup(t_error err)
{
	if (err == ERR_MAP_EXT)
		ft_putendl_fd("Invalid map: Bad file extension", STDERR_FILENO);
		
	if (err == ERR_MAP_READ)
		perror("Failed to read the map");

	if (err == ERR_MAP_ALLOC)
		perror("Failed to alloc the map");

	if (err == ERR_MAP_ISDIR)
		ft_putendl_fd("Invalid map: Is directory", STDERR_FILENO);

	if (err == ERR_MAP_EMPTY)
		ft_putendl_fd("Invalid map: Is empty", STDERR_FILENO);

	if (err == ERR_MAP_MATRIX)
		perror("Failed to create the map's matrix");
}

static void ft_puterr_map_format(t_error err)
{
	if (err == ERR_MAP_REG)
		ft_putendl_fd("Invalid map format: Rows are not uniform", STDERR_FILENO);

	if (err == ERR_MAP_RECT)
		ft_putendl_fd("Invalid map format: Is not rectangular", STDERR_FILENO);

	if (err == ERR_MAP_EXIT)
		ft_putendl_fd("Invalid map format: Bad exit points", STDERR_FILENO);

	if (err == ERR_MAP_START)
		ft_putendl_fd("Invalid map format: Bad start points", STDERR_FILENO);

	if (err == ERR_MAP_UNKNOWN)
		ft_putendl_fd("Invalid map format: Unknown components", STDERR_FILENO);

	if (err == ERR_MAP_SURRONDED)
		ft_putendl_fd("Invalid map format: Is not surronded by walls", STDERR_FILENO);

	if (err == ERR_MAP_COLLECTIBLE)
		ft_putendl_fd("Invalid map format: No collectibles", STDERR_FILENO);
}

void ft_print_map(t_error err)
{
	if (err >= ERR_MAP_EXT && err <= ERR_MAP_MATRIX)
		ft_puterr_map_setup(err);

	if (err >= ERR_MAP_REG && err <= ERR_MAP_COLLECTIBLE)
		ft_puterr_map_format(err);
}
