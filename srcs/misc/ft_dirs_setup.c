/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:45:52 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/27 11:51:09 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int **ft_dirs_setup(void)
{
	int **directions;
	
	directions = ft_matrix_alloc(2, TOTAL_DIRECTIONS);
	
	directions[0][0] = -1;
	directions[0][1] = 0;
	
	directions[1][0] = 1;
	directions[1][1] = 0;
	
	directions[2][0] = 0;
	directions[2][1] = -1;
	
	directions[3][0] = 0;
	directions[3][1] = 1;
	
	return (directions);
}
