/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:25:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 21:59:17 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_game_setup(t_game *g, char *map_path)
{
	t_map map;
	t_error err;

	err = ft_map_process(&map, map_path);
	if (err)
		return (err);

	g->map = map;
	g->avatar = ft_map_search(map, START_POINT, (t_coord){0, 0});

	return (OK);
}
