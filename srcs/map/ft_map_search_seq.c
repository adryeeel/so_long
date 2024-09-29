/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_search_seq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:35:04 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 23:56:03 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_coord ft_map_search_seq(t_map map, t_mapc comp)
{
	t_coord pos;
	static t_coord last;

	pos = ft_map_search(map, comp, last);

	if (pos.x < 0)
	{
		last.x = 0;
		last.y = 0;
		return (pos);
	}

	last.y = pos.y;
	last.x = pos.x + 1;

	return (pos);
}
