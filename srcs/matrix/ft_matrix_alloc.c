/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:30:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 15:00:58 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int **ft_matrix_alloc(size_t x, size_t y)
{
	size_t i;
	int **matrix;

	i = 0;
	matrix = ft_calloc(y + 1, sizeof(int *));

	if (!matrix)
		return (NULL);

	while (i < y)
	{
		matrix[i] = ft_calloc(x + 1, sizeof(int));

		if (!matrix[i])
		{
			ft_matrix_free(matrix);
			return (NULL);
		}
		i++;
	}

	matrix[i] = NULL;
	return (matrix);
}
