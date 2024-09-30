/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 21:09:55 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_xenv_setup(t_xenv *x, t_map map)
{
	int win_w;
	int win_h;
	t_error err;

	x->window = NULL;
	x->display = mlx_init();

	if (!x->display)
		return (ERR_XSRV_INIT);

	win_w = map.width * TILE_SIZE;
	win_h = map.height * TILE_SIZE;

	err = ft_ximg_setup(x->display, &(x->scene), win_w, win_h);
	if (err)
	{
		ft_xenv_free(*x);
		return (ft_error_scene(err));
	}

	err = ft_ximgf_setup(x->display, &(x->coll), COLL_IMG_PATH);
	if (err)
	{
		ft_xenv_free(*x);
		return (ft_error_coll(err));
	}

	return (OK);
}
