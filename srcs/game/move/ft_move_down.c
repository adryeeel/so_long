/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/20 00:42:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_down(t_game *game)
{
	t_map *map;
	t_avatar *avatar;
	
	map = game->map;
	avatar = game->avatar;
	
	if (avatar->y + TILE_SIZE < (int)map->height * TILE_SIZE)
		avatar->y += TILE_SIZE;
}
