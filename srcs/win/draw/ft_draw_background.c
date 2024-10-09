/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:05:18 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:01:23 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_background(void *display, t_ximg *tex)
{
	t_error err;
	t_ximg background;

	err = ft_ximgf_setup(display, &background, SPACE_IMG_PATH);

	if (err)
		return (err);

	ft_ximg_fill_alpha(tex, background, (t_coord){0, 0});
	ft_ximg_free(display, background);

	return (OK);
}
