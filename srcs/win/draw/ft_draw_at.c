/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:07:19 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/17 17:35:59 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_draw_at(t_ximg *dst, t_ximg src, t_coord coord)
{
	ft_ximg_copy(dst, src, (t_coord){
		coord.x * TILE_SIZE, 
		(coord.y + 1) * TILE_SIZE
	});
}

