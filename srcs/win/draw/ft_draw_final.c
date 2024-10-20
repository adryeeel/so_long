/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:23:17 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 18:40:56 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define FADE_OUT 0
#define RESTART 1
#define GOVER_TEXT 2

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

static t_error ft_draw_text(t_xenv x, char *text_path)
{
	t_error err;
	t_ximg text;
	t_coord draw_pos;

	err = ft_ximgf_setup(x.display, &text, text_path);
	if (err)
		return (err);

	draw_pos.x = (x.scene.width - text.width) / 2;
	draw_pos.y = (x.scene.height - text.height) / 2;

	ft_ximg_copy(&x.scene, text, draw_pos);

	ft_ximg_free(x.display, text);
	return (OK);
}

t_error ft_draw_final(t_xenv *x, t_game *g, char *screen_text)
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
		err = ft_draw_text(*x, screen_text);
		if (err)
			return (ft_error_gover(err)); // ! Generalize for won sprite error

		if (ft_delay(24))
			return (OK);
	}

	state = FADE_OUT;
	ft_game_restart(x, g);
	return (OK);
}
