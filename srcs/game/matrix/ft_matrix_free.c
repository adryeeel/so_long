/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:31:17 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/21 14:54:40 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_matrix_free(int **matrix)
{
	size_t i;

	if (!matrix)
		return;

	i = 0;

	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
