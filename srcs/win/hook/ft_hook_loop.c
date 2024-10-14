/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:57 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/14 17:36:08 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../../so_long.h"

#define FPS_16 64

static size_t ft_draw_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);

	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

int ft_hook_loop(void *param)
{
	t_xenv *x;
	t_game *g;
	t_error err;
	size_t curr_time;
	static size_t last_time;

	x = ((t_param *)param)->x;
	g = ((t_param *)param)->g;
	curr_time = ft_draw_time();

	if (curr_time - last_time < FPS_16)
		return (OK);

	err = ft_draw_anim(*x, g->map);
	if (err)
	{
		ft_error_print(err);
		mlx_loop_end(x->display);
	}

	last_time = curr_time;
	mlx_put_image_to_window(x->display, x->window, x->scene.id, 0, TILE_SIZE);

	return (0);
}
