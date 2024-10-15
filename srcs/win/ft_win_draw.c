/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:49:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 13:52:30 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_win_draw(t_xenv x, t_game g)
{
	t_error err;

	err = ft_draw_counter(x, g);
	if (err)
		return (err);

	err = ft_draw_comp(x, g, WALL);
	if (err)
		return (ft_error_wall(err));

	err = ft_draw_comp(x, g, SPACE);
	if (err)
		return (ft_error_space(err));

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (ft_error_avatar(err));

	err = ft_draw_comp(x, g, EXIT_POINT);
	if (err)
		return (ft_error_exit(err));

	return (OK);
}
