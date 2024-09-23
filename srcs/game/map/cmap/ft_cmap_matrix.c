/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmap_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:52:32 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 01:59:26 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

static void ft_populate(int **matrix, char *raw_map[], size_t x, size_t y)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			matrix[i][j] = ft_map_component(raw_map[i][j]);
			j++;
		}
		matrix[i][j] = -1;
		i++;
	}
}

int **ft_cmap_matrix(char *raw_map[])
{
	int **matrix;
	size_t width;
	size_t height;

	width = ft_strlen(raw_map[0]);
	height = ft_strarr_length(raw_map);
	matrix = ft_matrix_alloc(width, height);

	if (!matrix)
		return (NULL);

	ft_populate(matrix, raw_map, width, height);

	return (matrix);
}
