/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:13:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/12/19 03:30:15 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t ft_enemy_amount(t_map map)
{
	t_coord pos;
	size_t amount;

	amount = 0;
	pos = ft_map_search_seq(map, ENEMY);

	while (pos.x > 0)
	{
		pos = ft_map_search_seq(map, ENEMY);
		amount++;
	}

	return (amount);
}

t_error ft_enemy_setup(t_coord **enemies, t_map map)
{
	size_t i;
	t_coord pos;
	size_t amount;

	amount = ft_enemy_amount(map);
	if (!amount)
		return (OK);

	*enemies = ft_calloc(amount + 1, sizeof(t_coord));

	if (!*enemies)
		return (ERR_MAP_ENEMY);

	i = 0;
	pos = ft_map_search_seq(map, ENEMY);

	while (pos.x > 0)
	{
		pos = ft_map_search_seq(map, ENEMY);
		(*enemies)[i++] = pos;
	}

	return (OK);
}