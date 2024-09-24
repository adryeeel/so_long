/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:25:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 14:48:44 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_game_setup(t_game *g, char *map_path)
{
	t_map map;
	t_error err;

	g->avatar.x = 0;
	g->avatar.y = 0;

	err = ft_map_process(&map, map_path);
	if (err)
		return (err);

	g->map = map;

	return (OK);
}
