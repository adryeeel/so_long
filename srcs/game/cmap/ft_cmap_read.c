/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmap_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:33:56 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 00:34:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void ft_strtrim_nl(char **line)
{
	char *trimmed;

	trimmed = ft_strtrim(*line, "\n");
	free(*line);
	*line = trimmed;
}

char **ft_cmap_read(char *map_path)
{
	int map_fd;
	char *line;
	char **raw_map;

	raw_map = ft_calloc(1, sizeof(char *));

	if (!raw_map)
		return (NULL);

	map_fd = open(map_path, O_RDONLY);
	line = ft_readl(map_fd);

	if (!line || map_fd < 0)
	{
		free(raw_map);
		return (NULL);
	}

	while (line)
	{
		ft_strtrim_nl(&line);
		ft_wmap_push(&raw_map, line);
		free(line);
		line = ft_readl(map_fd);
	}

	close(map_fd);

	return (raw_map);
}
