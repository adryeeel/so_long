/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:47:54 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 04:26:06 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool ft_copy(char *dst[], char *src[], size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	return (true);
}

bool ft_map_push(char **grid[], char *line)
{
	size_t len;
	char **new_map;

	len = ft_strarr_length(*grid);
	new_map = ft_calloc(len + 1 + NULL_BYTE, sizeof(char *));

	if (!new_map)
		return (false);

	ft_copy(new_map, *grid, len);
	new_map[len] = ft_strdup(line);

	ft_map_free(*grid);
	*grid = new_map;

	return (true);
}
