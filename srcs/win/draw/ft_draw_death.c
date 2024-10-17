/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:23:16 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/17 17:37:18 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_death(t_xenv x, t_game g)
{
	t_ximg tex;
	t_error err;
	static bool was_drawn;

	if (was_drawn)
		return (OK);
	was_drawn = true;

	err = ft_ximgf_setup(x.display, &tex, DEATH_IMG_PATH);
	if (err)
		return (ft_error_death(err));

	ft_draw_background(x.display, &tex);

	ft_draw_at(&x.scene, tex, (t_coord){g.avatar.x, g.avatar.y});

	ft_ximg_free(x.display, tex);
	return (OK);
}