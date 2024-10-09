/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:12:39 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_map(t_error err)
{
	if (err >= ERR_MAP_REG && err <= ERR_MAP_COLLECTIBLE)
		ft_puterr_format(err);

	if (err >= ERR_MAP_PATH_EXIT && err <= ERR_MAP_PATH_ALLOC)
		ft_puterr_pathway(err);

	if (err == ERR_MAP_READ)
		perror("Failed to read the map's file");

	if (err == ERR_MAP_ALLOC)
		perror("Failed to allocate the map's grid");

	if (err == ERR_MAP_EMPTY)
		ft_putendl_fd("Invalid map: Is empty", STDERR_FILENO);

	if (err == ERR_MAP_ISDIR)
		ft_putendl_fd("Invalid map: Is directory", STDERR_FILENO);

	if (err == ERR_MAP_EXT)
		ft_putendl_fd("Invalid map: Bad file extension", STDERR_FILENO);
}
