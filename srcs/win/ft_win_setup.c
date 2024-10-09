/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:12:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 22:22:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define WIN_WH g.map.width *TILE_SIZE
#define WIN_HT (g.map.height + 1) * TILE_SIZE

t_error ft_win_setup(t_xenv *x, t_game g, t_param *args)
{
	x->window = mlx_new_window(x->display, WIN_WH, WIN_HT, "so_long");

	if (!x->window)
		return (ERR_WIN_CREATE);

	mlx_key_hook(x->window, ft_hook_key, args);
	mlx_close_hook(x->window, ft_hook_close, x);
	mlx_loop_hook(x->display, ft_hook_loop, args);

	return (ft_win_draw(*x, g));
}
