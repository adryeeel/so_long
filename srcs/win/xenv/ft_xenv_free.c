/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 16:46:53 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void ft_sprite_free(t_xenv x)
{
	if (x.scene.id)
		ft_ximg_free(x.display, x.scene);

	if (x.patrol.id)
		ft_ximg_free(x.display, x.patrol);

	if (x.coll.id)
		ft_ximg_free(x.display, x.coll);

	if (x.space.id)
		ft_ximg_free(x.display, x.space);
}

void ft_xenv_free(t_xenv x)
{
	int tmp;

	tmp = errno;

	if (!x.display)
		return;

	if (x.window)
		mlx_destroy_window(x.display, x.window);

	ft_sprite_free(x);

	mlx_destroy_display(x.display);
	free(x.display);

	errno = tmp;
}
