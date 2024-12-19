/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:25:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/12/19 03:48:48 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_game_setup(t_game *g, char *map_path)
{
	t_map map;
	t_error err;

	g->enemies = NULL;

	err = ft_map_process(&map, map_path);
	if (err)
		return (err);

	err = ft_enemy_setup(&g->enemies, map);
	if (err)
		return (err);

	ft_avatar_setup(&g->avatar, map);

	g->map = map;
	g->moves = 0;
	g->won = false;

	return (OK);
}
