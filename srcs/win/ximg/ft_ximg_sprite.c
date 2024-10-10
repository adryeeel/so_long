/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:38:29 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 15:27:25 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_ximg_sprite(t_xenv x, bool orient, t_ximg *tex, t_mapc comp)
{
	if (comp == AVATAR && orient == RIGHT)
		return (ft_ximgf_setup(x.display, tex, AVATAR_IMG_PATH));

	if (comp == AVATAR)
		return (ft_ximgf_setup(x.display, tex, LAVATAR_IMG_PATH));

	if (comp == SPACE)
		return (ft_ximgf_setup(x.display, tex, SPACE_IMG_PATH));

	if (comp == WALL)
		return (ft_ximgf_setup(x.display, tex, WALL_IMG_PATH));

	if (comp == EXIT_POINT)
		return (ft_ximgf_setup(x.display, tex, EXIT_IMG_PATH));

	return (OK);
}
