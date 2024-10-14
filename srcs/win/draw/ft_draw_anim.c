/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:39:11 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/14 16:35:08 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_anim(t_xenv x, t_game g)
{
	t_error err;
	static size_t frame_n;

	if (frame_n >= 12)
		frame_n = 0;

	err = ft_draw_frame(x, g.map, PATROL, frame_n);
	if (err)
		return (ft_error_patrol(err));

	err = ft_draw_frame(x, g.map, COLLECTIBLE, frame_n);
	if (err)
		return (ft_error_coll(err));

	frame_n++;
	return (OK);
}
