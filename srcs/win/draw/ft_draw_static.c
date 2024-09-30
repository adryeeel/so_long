/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:27:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:34 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_static(t_xenv x, t_game g)
{
	t_error err;

	err = ft_draw_comp(x, g.map, SPACE, BG_IMG_PATH);
	if (err)
		return (err);

	err = ft_draw_comp(x, g.map, WALL, WALL_IMG_PATH);
	if (err)
		return (ft_error_wall(err));

	return (OK);
}
