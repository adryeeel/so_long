/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:19:58 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define WIN_WH map.width * TILE_SIZE
#define WIN_HT (map.height + 1) * TILE_SIZE

static t_error ft_sprite_setup(t_xenv *x, t_map map)
{
	t_error err;

	err = ft_ximg_setup(x->display, &(x->scene), WIN_WH, WIN_HT);
	if (err)
		return (ft_error_scene(err));

	err = ft_ximgf_setup(x->display, &(x->coll), COLL_IMG_PATH);
	if (err)
		return (ft_error_coll(err));

	err = ft_ximgf_setup(x->display, &(x->patrol), PATROL_IMG_PATH);
	if (err)
		return (ft_error_patrol(err));

	err = ft_ximgf_setup(x->display, &(x->number), NUMBER_IMG_PATH);
	if (err)
		return (ft_error_counter(err));

	return (OK);
}

t_error ft_xenv_setup(t_xenv *x, t_map map)
{
	t_error err;

	x->window = NULL;
	x->display = mlx_init();
	x->allow_move = true;

	if (!x->display)
		return (ERR_XSRV_INIT);

	err = ft_sprite_setup(x, map);
	if (err)
	{
		ft_xenv_free(*x);
		return (err);
	}

	return (OK);
}
