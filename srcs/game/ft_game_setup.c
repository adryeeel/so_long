/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:25:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 15:50:41 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool ft_game_setup(t_game *g, char *map_path)
{
	t_map map;

	g->avatar.x = 0;
	g->avatar.y = 0;

	if (!ft_map_process(&map, map_path))
		return (false);

	g->map = map;

	return (true);
}
