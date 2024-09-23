/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:27:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 16:48:02 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_render_scene(t_xenv x, t_game g, t_ximg *scene)
{
	int win_h;
	int win_w;

	win_w = g.map.width * TILE_SIZE;
	win_h = g.map.height * TILE_SIZE;

	if (!ft_ximg_setup(x.display, scene, win_w, win_h))
		return (false);

	if (!ft_render_bg(x.display, scene))
	{
		ft_ximg_free(x.display, *scene);
		return (false);
	}

	mlx_put_image_to_window(x.display, x.window, scene->id, 0, 0);

	return (true);
}
