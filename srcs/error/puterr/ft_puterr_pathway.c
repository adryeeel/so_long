/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_pathway.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:28:43 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/06 01:30:43 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_pathway(t_error err)
{
	if (err == ERR_MAP_PATH_ALLOC)
		perror("Failed to alloc during map path checking");

	if (err == ERR_MAP_PATH_EXIT)
		ft_putendl_fd("Invalid map path: Exit point is not reachable", STDERR_FILENO);

	if (err == ERR_MAP_PATH_COLL)
		ft_putendl_fd("Invalid map path: Collectible is not reachable", STDERR_FILENO);
}
