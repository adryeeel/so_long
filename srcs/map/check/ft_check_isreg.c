/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isreg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 03:33:56 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_check_isreg(t_map map)
{
	size_t i;
	size_t row;

	i = 1;
	while (i < map.height)
	{
		row = ft_strlen(map.grid[i]);
		if (row != map.width)
			return (false);
		i++;
	}
	return (true);
}
