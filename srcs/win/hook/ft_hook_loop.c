/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:57 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:25:50 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../../so_long.h"

#define FPS_16 64

size_t ft_draw_time(void)
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
	t_param *data;
	static size_t last_time = 0;
	size_t curr_time = ft_draw_time();

	data = (t_param *)param;
	x = data->x;
	g = data->g;

	if (curr_time - last_time < FPS_16)
		return (OK);

	err = ft_draw_anim(*x, *g);
	if (err)
	{
		ft_error_print(err);
		mlx_loop_end(x->display);
	}

	last_time = curr_time;
	mlx_put_image_to_window(x->display, x->window, x->scene.id, 0, TILE_SIZE);

	return (0);
}
