/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:47:54 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/21 14:17:48 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

bool ft_wmap_push(char **raw_map[], char *line)
{
	size_t len;
	char **new_map;

	len = ft_strarr_length(*raw_map);
	new_map = ft_calloc(len + 1 + NULL_BYTE, sizeof(char *));

	if (!new_map)
		return (false);

	ft_copy(new_map, *raw_map, len);
	new_map[len] = ft_strdup(line);

	ft_wmap_free(*raw_map);
	*raw_map = new_map;

	return (true);
}
