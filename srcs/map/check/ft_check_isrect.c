/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_isrect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 22:40:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_check_isrect(char *raw_map[])
{
	size_t width;
	size_t height;

	width = ft_strlen(raw_map[0]);
	height = ft_strarr_length(raw_map);
	if (height >= width)
		return (false);
	return (true);
}
