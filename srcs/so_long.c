/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:11:40 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/21 18:50:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char const *argv[])
{
	t_error err;
	char *map_path;

	if (argc != 2)
	{
		ft_error_print(ERR_ARGS);
		return (EXIT_FAILURE);
	}

	map_path = (char *)argv[1];

	err = ft_game_start(map_path);
	if (err)
	{
		ft_error_print(err);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
