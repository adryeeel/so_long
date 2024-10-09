/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:28:43 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:48:54 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_format(t_error err)
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

	if (err == ERR_MAP_SURROUNDED)
		ft_putendl_fd("Invalid map format: Is not surrounded by walls", STDERR_FILENO);

	if (err == ERR_MAP_COLLECTIBLE)
		ft_putendl_fd("Invalid map format: No collectibles", STDERR_FILENO);
}
