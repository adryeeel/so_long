/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_restart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:09:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/17 18:30:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_game_restart(t_xenv x, t_game *g)
{
	g->moves = 0;
	g->avatar.died = false;
	
	// clear counter digits

	ft_win_draw(x, *g);
	ft_draw_anim(x, g);
}

