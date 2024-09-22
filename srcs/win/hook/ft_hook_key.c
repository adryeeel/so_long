/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:17:06 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 21:57:07 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define XK_LATIN1
#define XK_MISCELLANY

#include <X11/keysymdef.h>

int ft_hook_key(int key, void *param)
{
	t_xenv *x;
	t_game *g;
	t_param *data;

	data = (t_param *)param;
	x = data->x;
	g = data->g;

	if (key == XK_Escape)
		mlx_loop_end(x->display);

	if (key == XK_W || key == XK_w)
		ft_move_up(g);

	if (key == XK_A || key == XK_a)
		ft_move_left(g);

	if (key == XK_S || key == XK_s)
		ft_move_down(g);

	if (key == XK_D || key == XK_d)
		ft_move_right(g);

	return (0);
}
