/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:27:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 16:30:47 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_render_scene(t_xenv x, t_game g, t_ximg *scene)
{
	int win_h;
	int win_w;
	t_error err;

	win_w = g.map.width * TILE_SIZE;
	win_h = g.map.height * TILE_SIZE;

	err = ft_ximg_setup(x.display, scene, win_w, win_h);
	if (err)
		return (ft_error_scene(err));

	err = ft_render_bg(x.display, scene);
	if (err)
	{
		ft_ximg_free(x.display, *scene);
		return (ft_error_bg(err));
	}

	mlx_put_image_to_window(x.display, x.window, scene->id, 0, 0);

	return (OK);
}
