/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 17:04:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void ft_draw_seq(t_xenv x, t_map map, t_ximg tex, t_mapc comp)
{
	t_coord coord;

	coord = ft_map_search_seq(map, comp);

	while (coord.x >= 0)
	{
		ft_draw_at(&x.scene, tex, coord);
		coord = ft_map_search_seq(map, comp);
	}
}

static void ft_draw_single(t_xenv x, t_game g, t_ximg tex, t_mapc comp)
{
	t_coord coord;

	if (comp == AVATAR)
	{
		coord.x = g.avatar.x; 
		coord.y = g.avatar.y; 
	}
	else
		coord = ft_map_search(g.map, comp, (t_coord){0, 0});

	ft_draw_at(&x.scene, tex, coord);
}

t_error ft_draw_comp(t_xenv x, t_game g, t_mapc comp)
{
	t_ximg tex;
	t_error err;

	err = ft_ximg_sprite(x, g.avatar.orient, &tex, comp);
	if (err)
		return (err);

	if (comp == SPACE || comp == WALL)
	{
		ft_draw_seq(x, g.map, tex, comp);
		ft_ximg_free(x.display, tex);
		return (OK);
	}

	ft_draw_background(x.display, &tex);

	if (comp == COLLECTIBLE || comp == PATROL)
		ft_draw_seq(x, g.map, tex, comp);
	else
		ft_draw_single(x, g, tex, comp);

	ft_ximg_free(x.display, tex);
	return (OK);
}
