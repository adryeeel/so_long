/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/19 23:20:52 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_up(t_game *game)
{
	t_avatar *avatar;

	avatar = game->avatar;
	if (avatar->y - TILE_SIZE >= 0)
		avatar->y -= TILE_SIZE;
}
