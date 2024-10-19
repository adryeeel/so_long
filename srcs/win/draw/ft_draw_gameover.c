/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gameover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:29 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 00:32:37 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define FADE_OUT 0
#define RESTART 1
#define GOVER_TEXT 2

static t_error ft_draw_text(t_xenv x)
{
	t_error err;
	t_ximg text;
	t_coord draw_pos;

	err = ft_ximgf_setup(x.display, &text, GOVER_IMG_PATH);
	if (err)
		return (err);

	draw_pos.x = (x.scene.width - text.width) / 2;
	draw_pos.y = (x.scene.height - text.height) / 2;

	ft_ximg_copy(&x.scene, text, draw_pos);

	ft_ximg_free(x.display, text);
	return (OK);
}

static bool ft_delay(int frames)
{
	static int amount;

	if (amount >= frames)
	{
		amount = 0;
		return (false);
	}

	amount++;
	return (true);
}

t_error ft_draw_gameover(t_xenv *x, t_game *g)
{
	t_error err;
	static int state;

	if (state == FADE_OUT)
	{
		ft_draw_fadeout(*x);

		if (ft_delay(12))
			return (OK);
	}

	state = GOVER_TEXT;

	if (state == GOVER_TEXT)
	{
		err = ft_draw_text(*x);
		if (err)
			return (err);

		if (ft_delay(24))
			return (OK);
	}

	state = FADE_OUT;
	ft_game_restart(x, g);
	return (OK);
}
