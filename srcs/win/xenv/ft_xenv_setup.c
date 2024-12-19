/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/08 12:19:54 by arocha-b         ###   ########.fr       */
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
		return (ft_error(err, ERR_RENDSCENE));

	err = ft_ximgf_setup(x->display, &(x->coll), COLL_IMG_PATH);
	if (err)
		return (ft_error(err, ERR_RENDCOLL));

	err = ft_ximgf_setup(x->display, &(x->patrol), ENEMY_IMG_PATH);
	if (err)
		return (ft_error(err, ERR_RENDENEMY));

	err = ft_ximgf_setup(x->display, &(x->number), NUMBER_IMG_PATH);
	if (err)
		return (ft_error(err, ERR_RENDCOUNT));

	return (OK);
}

t_error ft_xenv_setup(t_xenv *x, t_map map)
{
	t_error err;

	x->display = mlx_init();
	if (!x->display)
		return (ERR_XSRV_INIT);

	x->window = NULL;
	x->coll.id = NULL;
	x->scene.id = NULL;
	x->number.id = NULL;
	x->patrol.id = NULL;
	x->allow_move = true;

	err = ft_sprite_setup(x, map);
	if (err)
	{
		ft_xenv_free(*x);
		return (err);
	}

	return (OK);
}
