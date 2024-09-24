/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 22:27:31 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_error ft_check_ext(char *map_path)
{
	char *ext;

	if (map_path[ft_strlen(map_path) - 1] == '/')
		return (ERR_MAP_ISDIR);

	ext = ft_strrchr(map_path, '.');
	if (!ext)
		return (ERR_MAP_EXT);

	if (ft_strncmp(ext + 1, "ber", ft_strlen(ext)) != 0)
		return (ERR_MAP_EXT);

	return (OK);
}
