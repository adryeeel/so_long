/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:42:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 17:55:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define DECIMAL 10
#define TEXT_WIDTH 102
#define DIGIT_WIDTH 10
#define DIGIT_SPACING 10

#define COUNTER_WIDTH TEXT_WIDTH + (digits * DIGIT_WIDTH) + (digits * DIGIT_SPACING)

static t_error ft_draw_text(t_xenv x, t_ximg *counter)
{
	t_ximg text;
	t_error err;

	err = ft_ximgf_setup(x.display, &text, COUNTER_IMG_PATH);
	if (err)
		return (err);

	ft_ximg_copy(counter, text, (t_coord){0, 0});

	ft_ximg_free(x.display, text);
	return (OK);
}

static t_error ft_draw_number(t_xenv x, t_ximg *counter, size_t moves)
{
	t_error err;
	size_t digit;
	t_ximg number;
	size_t draw_offset;

	draw_offset = counter->width - (DIGIT_SPACING + DIGIT_WIDTH) - 11;

	if (moves == 0)
	{
		err = ft_ximg_frame(x.display, x.number, &number, 0);
		if (err)
			return (err);

		ft_ximg_copy(counter, number, (t_coord){draw_offset, 0});
		ft_ximg_free(x.display, number);
	}

	while (moves > 0)
	{
		digit = moves % DECIMAL;

		err = ft_ximg_frame(x.display, x.number, &number, digit);
		if (err)
			return (err);

		ft_ximg_copy(counter, number, (t_coord){draw_offset, 0});

		moves /= DECIMAL;
		draw_offset -= (DIGIT_WIDTH + DIGIT_SPACING);

		ft_ximg_free(x.display, number);
	}

	return (OK);
}

t_error ft_draw_counter(t_xenv x, t_game g)
{
	t_error err;
	size_t digits;
	t_ximg counter;

	digits = ft_nbrlen(g.moves, DECIMAL);

	err = ft_ximg_setup(x.display, &counter, COUNTER_WIDTH, TILE_SIZE);
	if (err)
		return (err);

	err = ft_draw_text(x, &counter);
	if (err)
		return (err);

	err = ft_draw_number(x, &counter, g.moves);
	if (err)
		return (err);

	mlx_put_image_to_window(x.display, x.window, counter.id, 0, 0);

	ft_ximg_free(x.display, counter);
	return (OK);
}