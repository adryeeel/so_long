/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:33:56 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/07 23:57:28 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_strtrim_nl(char **line)
{
	char *trimmed;

	trimmed = ft_strtrim(*line, "\n");
	free(*line);
	*line = trimmed;
}

static t_error ft_read_setup(char **grid[], int *map_fd, char *map_path)
{
	if (!*grid)
	{
		*grid = ft_calloc(1, sizeof(char *));
		if (!*grid)
			return (ERR_MAP_ALLOC);
	}
	*map_fd = open(map_path, O_RDONLY);
	if (*map_fd < 0)
	{
		free(*grid);
		return (ERR_MAP_READ);
	}
	return (OK);
}

t_error ft_map_read(char **grid[], char *map_path)
{
	int map_fd;
	char *line;
	t_error err;

	map_fd = 0;

	err = ft_read_setup(grid, &map_fd, map_path);
	if (err)
		return (err);

	line = ft_readl(map_fd);
	while (line)
	{
		ft_strtrim_nl(&line);
		if (*line)
			ft_map_push(grid, line);
		free(line);
		line = ft_readl(map_fd);
	}

	close(map_fd);
	return (OK);
}
