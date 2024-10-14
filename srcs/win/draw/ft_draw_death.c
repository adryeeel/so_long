/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:23:16 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/14 17:29:10 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_death(t_xenv x, t_game g)
{
	t_ximg tex;
	t_error err;

	mlx_key_hook(x.window, NULL, NULL);

	err = ft_ximgf_setup(x.display, &tex, DEATH_IMG_PATH);
	if (err)
		return (err);

	ft_draw_background(x.display, &tex);

	ft_ximg_copy(&x.scene, tex, (t_coord){
		g.avatar.x * TILE_SIZE,
		g.avatar.y * TILE_SIZE,
	});

	ft_ximg_free(x.display, tex);
	return (OK);
}