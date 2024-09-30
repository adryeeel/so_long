/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:12:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:59 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_win_setup(t_xenv *x, t_game g)
{
	int win_w;
	int win_h;
	t_error err;
	t_param params;

	win_w = g.map.width * TILE_SIZE;
	win_h = (g.map.height + 1) * TILE_SIZE;

	x->window = mlx_new_window(x->display, win_w, win_h, "so_long");
	if (!x->window)
		return (ERR_WIN_CREATE);

	err = ft_draw_static(*x, g);
	if (err)
		return (err);

	params.g = &g;
	params.x = x;

	mlx_close_hook(x->window, ft_hook_close, x);
	mlx_key_hook(x->window, ft_hook_key, &params);
	mlx_loop_hook(x->display, ft_hook_loop, &params);

	mlx_loop(x->display);

	ft_xenv_free(*x);
	ft_game_free(g);

	return (OK);
}
