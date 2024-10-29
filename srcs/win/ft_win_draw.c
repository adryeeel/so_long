/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:49:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/24 00:06:12 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_win_draw(t_xenv x, t_game g)
{
	t_error err;

	err = ft_draw_counter(x, g);
	if (err)
		return (ft_error(err, ERR_RENDCOUNT));

	err = ft_draw_comp(x, g, WALL);
	if (err)
		return (ft_error(err, ERR_RENDWALL));

	err = ft_draw_comp(x, g, SPACE);
	if (err)
		return (ft_error(err, ERR_RENDSPACE));

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (ft_error(err, ERR_RENDAVATAR));

	err = ft_draw_comp(x, g, EXIT_POINT);
	if (err)
		return (ft_error(err, ERR_RENDEXIT));

	return (OK);
}
