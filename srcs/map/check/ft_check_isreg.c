/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isreg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 22:40:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_check_isreg(char *raw_map[])
{
	size_t i;
	size_t row;
	size_t width;
	size_t height;

	width = ft_strlen(raw_map[0]);
	height = ft_strarr_length(raw_map);

	i = 1;
	while (i < height)
	{
		row = ft_strlen(raw_map[i]);
		if (row != width)
			return (false);
		i++;
	}
	return (true);
}
