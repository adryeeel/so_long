/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:46:18 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:16:30 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define XK_LATIN1
#define XK_MISCELLANY

#include <X11/keysymdef.h>

static void ft_draw(t_xenv x, t_game g)
{
	t_error err;

	err = ft_draw_move(x, g);
	if (err)
	{
		ft_error_print(err);
		mlx_loop_end(x.display);
		return;
	}
	mlx_put_image_to_window(x.display, x.window, x.scene.id, 0, 0);
}

static void ft_move(int key, t_game *g)
{
	if (key == XK_W || key == XK_w)
		ft_move_up(g);

	if (key == XK_A || key == XK_a)
		ft_move_left(g);

	if (key == XK_S || key == XK_s)
		ft_move_down(g);

	if (key == XK_D || key == XK_d)
		ft_move_right(g);
}

void ft_key_move(t_xenv x, t_game *g, int key)
{
	if (key == XK_Escape)
		mlx_loop_end(x.display);

	ft_move(key, g);
	ft_draw(x, *g);
}
