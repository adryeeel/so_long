/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gameover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:29 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/18 18:41:25 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_draw_gameover(t_xenv *x, t_game *g)
{
	if (ft_draw_fadeout(*x))
		return;

	ft_game_restart(x, g);
}
