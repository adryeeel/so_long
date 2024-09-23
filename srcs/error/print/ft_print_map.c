/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 20:19:01 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_print_map(t_error err)
{
	if (err == ERR_MAP_READ)
		perror("Failed to read the game's map");

	if (err == ERR_MAP_RECT)
		ft_putendl_fd("Invalid map: Is not rectangular", STDERR_FILENO);

	if (err == ERR_MAP_SYMM)
		ft_putendl_fd("Invalid map: Rows are not symmetrical", STDERR_FILENO);

	if (err == ERR_MAP_MATRIX)
		perror("Failed to create the map's matrix");
}
