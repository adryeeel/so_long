/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gameover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:29 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/18 14:30:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define MS_500 6

static bool ft_delay(size_t frames)
{
	static unsigned total;

	if (total <= frames)
	{
		total++;
		return (true);
	}
	return (false);
}

void ft_draw_gameover(t_xenv *x, t_game *g)
{
	if (ft_delay(MS_500))
		return;

	if (ft_draw_fadeout(*x))
		return;

	ft_game_restart(x, g);
}
