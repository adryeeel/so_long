/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:12:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 16:47:11 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool ft_win_setup(t_xenv x, t_game g)
{
	int win_w;
	int win_h;
	t_ximg scene;
	t_param params;

	win_w = g.map.width * TILE_SIZE;
	win_h = g.map.height * TILE_SIZE;

	x.window = mlx_new_window(x.display, win_w, win_h, "so_long");

	if (!x.window)
		return (false);

	params.g = &g;
	params.x = &x;

	mlx_close_hook(x.window, ft_hook_close, &x);
	mlx_key_hook(x.window, ft_hook_key, &params);

	if (!ft_render_scene(x, g, &scene))
	{
		ft_xenv_free(x);
		ft_game_free(g);
		return (false);
	}

	mlx_loop(x.display);

	ft_ximg_free(x.display, scene);
	ft_xenv_free(x);
	ft_game_free(g);

	return (true);
}
