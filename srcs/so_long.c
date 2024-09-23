/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:11:40 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 02:17:51 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char const *argv[])
{
	char *map_path;

	if (argc < 2)
	{
		ft_putendl_fd("Error: Map wasn't provided as argument", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_putendl_fd("Error: Too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	map_path = (char *)argv[1];

	if (!ft_game_start(map_path))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
